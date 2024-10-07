/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:51 by madamou           #+#    #+#             */
/*   Updated: 2024/10/07 13:35:52 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"
#include <time.h>

void	ft_all_push_in_b(t_stacks *stacks, int *pivots)
{
	int	tmp;

	if (stacks->len.a == 3)
		return ;
	tmp = stacks->len.a;
	while (stacks->len.a > (tmp / 2) && stacks->len.a > 3)
	{
		while (stacks->stack_a->nb > pivots[0])
			ft_rotate_a(stacks, 1);
		ft_push_b(stacks);
		if (stacks->stack_b->nb >= pivots[1])
			ft_rotate_b(stacks, 1);
	}
	ft_find_pivot(stacks->stack_a, stacks->len.a, pivots);
	ft_all_push_in_b(stacks, pivots);
}

void	ft_final_sort(t_stacks *stacks)
{
	if (stacks->stack_a->nb > stacks->mediane)
	{
		while (stacks->first_a->nb > stacks->last_a->nb)
			ft_rotate_a(stacks, 2);
	}
	else
	{
		while (stacks->last_a->nb < stacks->first_a->nb)
			ft_rev_rotate_a(stacks, 2);
	}
}

void set_stacks(t_stacks *stacks, t_stack *stack_a)
{
	stacks->stack_a = stack_a;
	stacks->first_a = stack_a;
	while (stack_a->next)
		stack_a = stack_a->next;
	stacks->len.a = ft_len_stack(stacks->stack_a);
	stacks->last_a = stack_a;
	stacks->stack_b = NULL;
	stacks->first_b = NULL;
	stacks->last_b = NULL;
	stacks->len.b = 0;
}

t_stack	*ft_push_swap(t_stack *stack_a)
{
	t_stacks	stacks;
	int	pivot[2];

	set_stacks(&stacks, stack_a);
	ft_find_pivot(stacks.stack_a, stacks.len.a, pivot);
	stacks.mediane = pivot[0];
	if (stacks.len.a == 2)
		return (ft_2_numbers(&stacks), stacks.stack_a);
	if (stacks.len.a > 5)
		ft_all_push_in_b(&stacks, pivot);
	else
	{
		while (stacks.len.a > 3)
			ft_push_b(&stacks);
	}
	ft_if_3_numbers(&stacks);
	ft_stock_movement("", 2, &stacks);
	ft_pa_ra_or_rra(&stacks);
	ft_final_sort(&stacks);
	return (stacks.stack_a);
}
