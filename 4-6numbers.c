/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-6numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:51 by madamou           #+#    #+#             */
/*   Updated: 2024/04/29 21:26:22 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack *ft_before_6_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int len_stack;
	int pivot;
	
	ft_push_b(stack_a, stack_b, 0);
	len_stack = ft_len_stack(stack_a);
	pivot = ft_find_pivot(stack_a);
	while (ft_len_stack(stack_a) > 3)
	{
		if (ft_normal_or_rev(stack_a, ft_len_stack(stack_a), pivot))
		{
			while (ft_find_biggest_nb(stack_a, pivot) != 1)
				stack_a = ft_rotate_a(stack_a);
			stack_a = ft_push_b(stack_a, stack_b, 1);
		}
		else
		{
			while (ft_find_biggest_nb_inverse(stack_a, pivot) != ft_len_stack(stack_a))
				stack_a = ft_rev_rotate_a(stack_a);
			stack_a = ft_rev_rotate_a(stack_a);
			stack_a = ft_push_b(stack_a, stack_b, 1);
		}
	}
	stack_b = ft_push_b(stack_a, stack_b, 2);
	stack_a = ft_if_3_numbers(stack_a, NULL);
	if (ft_len_stack(stack_b) == 3)
		stack_b = ft_if_3_numbers_inverse(stack_b, NULL);
	else if (ft_len_stack(stack_b) == 2)
		stack_b = ft_if_2_numbers_inverse(stack_b);
	while (ft_len_stack(stack_a) < len_stack)
	{
		stack_a = ft_push_a(stack_a, stack_b, 1);
		stack_b = ft_push_a(stack_a, stack_b, 2);
	}
	return (stack_a);
}
