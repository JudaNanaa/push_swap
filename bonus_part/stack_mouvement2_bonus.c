/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/08/28 21:37:35 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_stack	*ft_rev_rotate_a_bonus(t_stack *stack_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = stack_a;
	if (ft_len_stack(stack_a) <= 1)
		return (stack_a);
	before_last = stack_a;
	while (stack_a->next)
	{
		before_last = stack_a;
		stack_a = stack_a->next;
	}
	last = stack_a;
	last->next = first;
	before_last->next = NULL;
	return (last);
}

t_stack	*ft_rev_rotate_b_bonus(t_stack *stack_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = stack_b;
	if (ft_len_stack(stack_b) <= 1)
		return (stack_b);
	before_last = stack_b;
	while (stack_b->next)
	{
		before_last = stack_b;
		stack_b = stack_b->next;
	}
	last = stack_b;
	last->next = first;
	before_last->next = NULL;
	return (last);
}

t_stacks	*ft_push_a_bonus(t_stacks *st)
{
	t_stack	*tmp;

	if (!st->stack_b)
		return (st);
	tmp = st->stack_b;
	st->stack_b = st->stack_b->next;
	tmp->next = st->stack_a;
	st->stack_a = tmp;
	return (st);
}

t_stacks	*ft_push_b_bonus(t_stacks *stacks)
{
	t_stack	*tmp;

	if (!stacks->stack_a)
		return (stacks);
	tmp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	return (stacks);
}
