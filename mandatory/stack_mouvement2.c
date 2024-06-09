/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/06/09 13:32:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_rev_rotate_a(t_stacks *stacks, int cas)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = stacks->stack_a;
	if (ft_len_stack(stacks->stack_a) <= 1)
		return (stacks->stack_a);
	while (stacks->stack_a->next)
	{
		before_last = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
	}
	last = stacks->stack_a;
	last->next = first;
	before_last->next = NULL;
	if (cas == 1)
		ft_stock_movement("rra\n", 1, stacks);
	return (last);
}

t_stack	*ft_rev_rotate_b(t_stacks *stacks, int cas)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = stacks->stack_b;
	if (ft_len_stack(stacks->stack_b) <= 1)
		return (stacks->stack_b);
	while (stacks->stack_b->next)
	{
		before_last = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
	}
	last = stacks->stack_b;
	last->next = first;
	before_last->next = NULL;
	if (cas == 1)
		ft_stock_movement("rrb\n", 1, stacks);
	return (last);
}

t_stacks	*ft_push_a(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
	ft_stock_movement("", 2, stacks);
	write(1, "pa\n", 3);
	return (stacks);
}

t_stacks	*ft_push_b(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	ft_stock_movement("", 2, stacks);
	write(1, "pb\n", 3);
	return (stacks);
}
