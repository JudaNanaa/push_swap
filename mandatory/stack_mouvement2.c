/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/10/05 21:10:39 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_rev_rotate_a(t_stacks *stacks, int cas)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->len_stacka <= 1)
		return ;
	first = stacks->stack_a;
	before_last = stacks->stack_a;
	while (stacks->stack_a->next)
	{
		before_last = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
	}
	last = stacks->stack_a;
	last->next = first;
	before_last->next = NULL;
	stacks->first_a = last;
	stacks->stack_a = last;
	stacks->last_a = before_last;
	if (cas == 1)
		ft_stock_movement("rra\n", 1, stacks);
	if (cas == 2)
		ft_write(STDOUT_FILENO, "rra\n", 4);
}

void	ft_rev_rotate_b(t_stacks *stacks, int cas)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->len_stackb <= 1)
		return ;
	first = stacks->stack_b;
	before_last = stacks->stack_b;
	while (stacks->stack_b->next)
	{
		before_last = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
	}
	last = stacks->stack_b;
	last->next = first;
	before_last->next = NULL;
	stacks->first_b = last;
	stacks->stack_b = last;
	stacks->last_b = before_last;
	if (cas == 1)
		ft_stock_movement("rrb\n", 1, stacks);
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack	*first_b;
	t_stack	*second_b;

	first_b = stacks->stack_b;
	second_b = stacks->stack_b->next;
	first_b->next = stacks->stack_a;
	stacks->stack_b = second_b;
	stacks->first_b = second_b;
	stacks->stack_a = first_b;
	stacks->first_a = first_b;
	if (!stacks->last_a)
		stacks->last_a = first_b;
	ft_stock_movement("", 2, stacks);
	ft_write(1, "pa\n", 3);
	++stacks->len_stacka;
	--stacks->len_stackb;
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*second_a;

	first_a = stacks->stack_a;
	second_a = stacks->stack_a->next;
	first_a->next = stacks->stack_b;
	stacks->stack_a = second_a;
	stacks->first_a = second_a;
	stacks->stack_b = first_a;
	stacks->first_b = first_a;
	if (!stacks->last_b)
		stacks->last_b = first_a;
	ft_stock_movement("", 2, stacks);
	ft_write(1, "pb\n", 3);
	--stacks->len_stacka;
	++stacks->len_stackb;
}
