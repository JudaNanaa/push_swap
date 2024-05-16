/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:00:31 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:35:57 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_swap_a(t_stack *stack_a)
{
	t_stack	*buff;

	buff = stack_a;
	if (ft_len_stack(stack_a) <= 1)
		return (stack_a);
	stack_a = stack_a->next;
	buff->next = stack_a->next;
	stack_a->next = buff;
	write(1, "sa\n", 3);
	return (stack_a);
}

t_stack	*ft_swap_b(t_stack *stack_b)
{
	t_stack	*buff;

	buff = stack_b;
	if (ft_len_stack(stack_b) <= 1)
		return (stack_b);
	stack_b = stack_b->next;
	buff->next = stack_b->next;
	stack_b->next = buff;
	write(1, "sb\n", 3);
	return (stack_b);
}

t_stack	*ft_rotate_a(t_stack *stack_a, int cas)
{
	t_stack	*buff;
	t_stack	*second;

	buff = stack_a;
	second = stack_a->next;
	if (ft_len_stack(stack_a) <= 1)
		return (stack_a);
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = buff;
	buff->next = NULL;
	if (cas == 1)
		write(1, "ra\n", 3);
	return (second);
}

t_stack	*ft_rotate_b(t_stack *stack_b, int cas)
{
	t_stack	*buff;
	t_stack	*second;

	buff = stack_b;
	second = stack_b->next;
	if (ft_len_stack(stack_b) <= 1)
		return (stack_b);
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = buff;
	buff->next = NULL;
	if (cas == 1)
		write(1, "rb\n", 3);
	return (second);
}
