/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:32:57 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:35:09 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

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
			return (stack_a = ft_rotate_a(tmp, 1), ft_if_3_numbers(stack_a,
					stack_b));
		if (buff < stack_a->nb && stack_a->nb > (stack_a->next)->nb
			&& buff > (stack_a->next)->nb)
			return (stack_a = ft_rev_rotate_a(tmp, 1), ft_if_3_numbers(stack_a,
					stack_b));
		else
			return (stack_a = ft_swap_a(tmp), ft_if_3_numbers(stack_a,
					stack_b));
	}
	return (tmp);
}
