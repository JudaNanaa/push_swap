/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:32:57 by madamou           #+#    #+#             */
/*   Updated: 2024/04/29 20:16:45 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_if_3_numbers(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		buff;

	tmp = stack_a;
	buff = stack_a->nb;
	stack_a = stack_a->next;
	if (ft_check_if_sort(tmp, stack_b) == false)
	{
		if (buff > stack_a->nb && stack_a->nb < (stack_a->next)->nb
			&& buff > (stack_a->next)->nb)
			return (stack_a = ft_rotate_a(tmp), ft_if_3_numbers(stack_a, stack_b));
		if (buff < stack_a->nb && stack_a->nb > (stack_a->next)->nb
			&& buff > (stack_a->next)->nb)
			return (stack_a = ft_rev_rotate_a(tmp), ft_if_3_numbers(stack_a, stack_b));
		else
			return (stack_a = ft_swap_a(tmp), ft_if_3_numbers(stack_a, stack_b));
	}
	return (tmp);
}

t_stack	*ft_if_3_numbers_inverse(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		buff;

	tmp = stack_a;
	buff = stack_a->nb;
	stack_a = stack_a->next;
	if (ft_check_if_sort_inverse(tmp, stack_b) == false)
	{
		if (buff < stack_a->nb && stack_a->nb > (stack_a->next)->nb
			&& buff < (stack_a->next)->nb)
			return (stack_a = ft_rotate_b(tmp), ft_if_3_numbers_inverse(stack_a, stack_b));
		if (buff > stack_a->nb && stack_a->nb < (stack_a->next)->nb
			&& buff < (stack_a->next)->nb)
			return (stack_a = ft_rev_rotate_b(tmp), ft_if_3_numbers_inverse(stack_a, stack_b));
		else
			return (stack_a = ft_swap_b(tmp), ft_if_3_numbers_inverse(stack_a, stack_b));
	}
	return (tmp);
}
