/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-6numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:51 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 20:03:57 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_other_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	len_stack;
	int	pivot;
	int i;
	t_stacks *imad;

	imad = malloc(sizeof(t_stacks));
	if (!imad)
		return (NULL);
	imad->stack_a = stack_a;
	imad->stack_b = stack_b;
	len_stack = ft_len_stack(imad->stack_a);
	i = len_stack;
	pivot = ft_find_pivot(imad->stack_a, len_stack);
	if (len_stack == 2)
		return (ft_if_2_numbers(imad->stack_a));
	while (i-- > 3)
	{
		imad = ft_push_b(imad);
		if (imad->stack_b->nb > pivot)
			imad->stack_b = ft_rotate_b(imad->stack_b, 1);
	}
	imad->stack_a = ft_if_3_numbers(imad->stack_a, NULL);
	i = 3;
	while (i < len_stack)
	{
		imad = ft_pa_ra_or_rra(imad, len_stack - i, i);
		i++;
	}
	if (imad->stack_a->nb > pivot)
	{
		while (!ft_check_if_sort(imad->stack_a, imad->stack_b))
			imad->stack_a = ft_rotate_a(imad->stack_a, 1);
	}
	else
	{
		while (!ft_check_if_sort(imad->stack_a, imad->stack_b))
			imad->stack_a = ft_rev_rotate_a(imad->stack_a, 1);
	}
	return (stack_a = imad->stack_a, free(imad), stack_a);
}
