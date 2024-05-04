/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/05/02 21:28:15 by madamou          ###   ########.fr       */
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
		ft_printf("rra\n");
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
	ft_printf("rrb\n");
	return (last);
}

t_stack	*ft_push_a(t_stack *stack_a, t_stack *stack_b, int cas)
{
	int buff;
	static t_stack *stat;

	if (cas == 0)
		stat = NULL;
	if (cas == 1)
	{
		buff = stack_b->nb;
		stack_b = ft_del_up_stack(stack_b);
		stack_a = ft_push_stack(stack_a, buff);
		stat = stack_b;
		stack_b = stat;
		ft_printf("pa\n");
		return (stack_a);
	}
	return (stat);
}

t_stack	*ft_push_b(t_stack *stack_a, t_stack *stack_b, int cas)
{
	int buff;
	static t_stack *stat;
	t_stack *tmp;

	if (cas == 0)
		stat = NULL;
	if (cas == 1)
	{
		buff = stack_a->nb;
		stack_a = ft_del_up_stack(stack_a);
		stack_b = ft_push_stack(stack_b, buff);
		tmp = stack_b;
		stat = tmp;
		ft_printf("pb\n");
		return (stack_a);
	}
	return (stat);
}
