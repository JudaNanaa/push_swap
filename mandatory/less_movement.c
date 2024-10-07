/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:38:52 by madamou           #+#    #+#             */
/*   Updated: 2024/10/07 02:02:56 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"
#include <stdio.h>
#include <math.h>

int	ft_find_next_fork(t_stack *first, t_stack *last, int nb, int len);

void	ft_pa_ra_or_rra(t_stacks *stacks)
{
	t_int index;
	
	if (stacks->len.b == 0)
		return;
	ft_less_movement(stacks);
	index.a = stacks->index.a;
	index.b = stacks->index.b;
	if (index.a < stacks->len.a / 2 && index.b < stacks->len.b / 2)
	{
		while (index.a && index.b)
			(ft_db_rotate(stacks), --index.a, --index.b);
		while (index.a)
			(ft_rotate_a(stacks, 2), --index.a);
		while (index.b)
			(ft_rotate_b(stacks, 2), --index.b);
	}
	else if (index.a >= stacks->len.a / 2 && index.b >= stacks->len.b / 2)
	{
		while (index.a < stacks->len.a && index.b < stacks->len.b)
			(ft_db_rev_rotate(stacks), ++index.a, ++index.b);
		while (index.a < stacks->len.a)
			(ft_rev_rotate_a(stacks, 2), ++index.a);
		while (index.b < stacks->len.b)
			(ft_rev_rotate_b(stacks, 2), ++index.b);
	}
	else
	{
		if (index.a < stacks->len.a / 2)
		{
			while (index.a)
				(ft_rotate_a(stacks, 2), --index.a);
		}
		else
		{
			while (index.a < stacks->len.a)
				(ft_rev_rotate_a(stacks, 2), ++index.a);
		}
		if (index.b < stacks->len.b / 2)
		{
			while (index.b)
				(ft_rotate_b(stacks, 2), --index.b);
		}
		else
		{
			while (index.b < stacks->len.b)
				(ft_rev_rotate_b(stacks, 2), ++index.b);
		}
	}
	ft_push_a(stacks);
	ft_pa_ra_or_rra(stacks);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

int	ft_less_movement(t_stacks *stacks)
{
	int current_cost;
	int save_cost;
	int save_nb;
	int i;
	int next_in_a;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = stacks->stack_a;
	b = stacks->stack_b;
	save_cost = -1;
	save_nb = 0;
	while (i < stacks->len.b)
	{
		next_in_a = ft_find_next_fork(a, stacks->last_a, b->nb, stacks->len.a);
		if ((next_in_a < stacks->len.a / 2 && i < stacks->len.b / 2)
			|| (next_in_a >= stacks->len.a / 2 && i >= stacks->len.b / 2))
			current_cost = ft_max(ft_min(next_in_a, stacks->len.a - next_in_a), ft_min(i, stacks->len.b - i));
		else
		{
		 	current_cost = ft_min(next_in_a, stacks->len.a - next_in_a) + ft_min(i, stacks->len.b - i);
		}
		if (save_cost > current_cost || save_cost == -1
			 || (save_cost == current_cost && save_nb < b->nb))
		{
			save_cost = current_cost;
			stacks->index.a = next_in_a;
			stacks->index.b = i;
			save_nb = b->nb;
		}
		b = b->next;
		++i;
	}
	return (save_nb);
}


int	ft_find_nb(t_stack *stack, int nb)
{
	int	index;

	index = 0;
	while (stack->nb != nb)
	{
		stack = stack->next;
		++index;
	}
	return (index);
}

int	ft_find_nb_stacka(t_stack *stack_a, int nb)
{
	int	index;
	int	next;

	index = 0;
	next = ft_find_next(stack_a, nb);
	while (stack_a && stack_a->nb != next)
	{
		stack_a = stack_a->next;
		index++;
	}
	return (index);
}
