/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 18:25:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_rev_rotate_a(t_stack *stack_a, int cas)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = stack_a;
	if (ft_len_stack(stack_a) <= 1)
		return (stack_a);
	while (stack_a->next)
	{
		before_last = stack_a;
		stack_a = stack_a->next;
	}
	last = stack_a;
	last->next = first;
	before_last->next = NULL;
	if (cas == 1)
		// ft_stock_movements("rra\n", 1);
		write(1, "rra\n", 4);
	return (last);
}

t_stack	*ft_rev_rotate_b(t_stack *stack_b, int cas)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = stack_b;
	if (ft_len_stack(stack_b) <= 1)
		return (stack_b);
	while (stack_b->next)
	{
		before_last = stack_b;
		stack_b = stack_b->next;
	}
	last = stack_b;
	last->next = first;
	before_last->next = NULL;
	if (cas == 1)
		// ft_stock_movements("rrb\n", 1);
		write(1, "rrb\n", 4);
	return (last);
}

t_stack	*ft_push_a(t_stack *stack_a, t_stack *stack_b, int cas)
{
	static t_stack	*stat;
	t_stack			*tmp;

	if (cas == 0)
		stat = NULL;
	if (cas == 1)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		stat = stack_b;
		tmp->next = stack_a;
		stack_a = tmp;
		// ft_stock_movements("pa\n", 1);
		write(1, "pa\n", 3);
		return (stack_a);
	}
	return (stat);
}

t_stacks	*ft_push_b(t_stacks *stacks)
{
	t_stack			*tmp;
	
	tmp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	// ft_stock_movements("pb\n", 1);
	write(1, "pb\n", 3);
	return (stacks);
}
