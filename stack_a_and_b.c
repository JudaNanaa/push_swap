/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_and_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:07:56 by madamou           #+#    #+#             */
/*   Updated: 2024/04/29 20:22:01 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_push_swap(t_stack *stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	if (ft_len_stack(stack_a) == 2)
		stack_a = ft_if_2_numbers(stack_a);
	if (ft_len_stack(stack_a) == 3)
		stack_a = ft_if_3_numbers(stack_a, stack_b);
	if (ft_len_stack(stack_a) > 3 
		&& ft_len_stack(stack_a) <= 6)
		stack_a = ft_before_6_numbers(stack_a, stack_b);
	return (stack_a);
}
