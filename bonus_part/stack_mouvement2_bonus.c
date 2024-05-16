/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:37:08 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_stack	*ft_rev_rotate_a(t_stack *stack_a)
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
	return (last);
}

t_stack	*ft_rev_rotate_b(t_stack *stack_b)
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
	return (last);
}

t_stacks	*ft_push_a(t_stacks *st)
{
	t_stack	*tmp;

	tmp = st->stack_b;
	st->stack_b = st->stack_b->next;
	tmp->next = st->stack_a;
	st->stack_a = tmp;
	return (st);
}

t_stacks	*ft_push_b(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	return (stacks);
}
