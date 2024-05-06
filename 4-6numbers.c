/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-6numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:51 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 00:29:27 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_other_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	len_stack;
	int	pivot;
	int i;

	ft_push_b(stack_a, stack_b, 0);
	len_stack = ft_len_stack(stack_a);
	i = len_stack;
	pivot = ft_find_pivot(stack_a);
	if (len_stack == 2)
		return (ft_if_2_numbers(stack_a));
	while (i-- > 3)
	{
		stack_a = ft_push_b(stack_a, stack_b, 1);
		stack_b = ft_push_b(stack_a, stack_b, 2);
		if (stack_b->nb > pivot)
			stack_b = ft_rotate_b(stack_b, 1);
	}
	stack_a = ft_if_3_numbers(stack_a, NULL);
	i = 3;
	while (i++ < len_stack)
	{
		stack_a = ft_pa_ra_or_rra(stack_a, stack_b, 1, i - 1);
		stack_b = ft_pa_ra_or_rra(stack_a, stack_b, 2, i - 1);
	}
	if (stack_a->nb > pivot)
	{
		while (!ft_check_if_sort(stack_a, stack_b))
			stack_a = ft_rotate_a(stack_a, 1);
	}
	else
	{
		while (!ft_check_if_sort(stack_a, stack_b))
			stack_a = ft_rev_rotate_a(stack_a, 1);
	}
	return (stack_a);
}
