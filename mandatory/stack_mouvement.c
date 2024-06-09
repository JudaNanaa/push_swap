/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:00:31 by madamou           #+#    #+#             */
/*   Updated: 2024/06/09 13:30:48 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_swap_a(t_stacks *stacks)
{
	t_stack	*buff;

	buff = stacks->stack_a;
	if (ft_len_stack(stacks->stack_a) <= 1)
		return (stacks->stack_a);
	stacks->stack_a = stacks->stack_a->next;
	buff->next = stacks->stack_a->next;
	stacks->stack_a->next = buff;
	write(1, "sa\n", 3);
	return (stacks->stack_a);
}

t_stack	*ft_swap_b(t_stacks *stacks)
{
	t_stack	*buff;

	buff = stacks->stack_b;
	if (ft_len_stack(stacks->stack_b) <= 1)
		return (stacks->stack_b);
	stacks->stack_b = stacks->stack_b->next;
	buff->next = stacks->stack_b->next;
	stacks->stack_b->next = buff;
	write(1, "sb\n", 3);
	return (stacks->stack_b);
}

t_stack	*ft_rotate_a(t_stacks *stacks, int cas)
{
	t_stack	*buff;
	t_stack	*second;

	buff = stacks->stack_a;
	second = stacks->stack_a->next;
	if (ft_len_stack(stacks->stack_a) <= 1)
		return (stacks->stack_a);
	while (stacks->stack_a->next)
		stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->next = buff;
	buff->next = NULL;
	if (cas == 1)
		ft_stock_movement("ra\n", 1);
	return (second);
}

t_stack	*ft_rotate_b(t_stacks *stacks, int cas)
{
	t_stack	*buff;
	t_stack	*second;

	buff = stacks->stack_b;
	second = stacks->stack_b->next;
	if (ft_len_stack(stacks->stack_b) <= 1)
		return (stacks->stack_b);
	while (stacks->stack_b->next)
		stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->next = buff;
	buff->next = NULL;
	if (cas == 1)
		ft_stock_movement("rb\n", 1);
	return (second);
}
