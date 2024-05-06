/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_and_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:07:56 by madamou           #+#    #+#             */
/*   Updated: 2024/05/04 20:19:09 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = ft_other_numbers(stack_a, stack_b);
	return (stack_a);
}
