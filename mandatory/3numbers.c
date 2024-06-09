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

t_stack	*ft_if_3_numbers(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	while (ft_check_if_sort(stacks->stack_a, NULL) == 0)
	{
		first = stacks->stack_a->nb;
		second = stacks->stack_a->next->nb;
		third = stacks->stack_a->next->next->nb;
		if (first > second && first > third && second < third)
			stacks->stack_a = ft_rotate_a(stacks, 1);
		else if (first < second && first > third && second > third)
			stacks->stack_a = ft_rev_rotate_a(stacks, 1);
		else
			stacks->stack_a = ft_swap_a(stacks);
	}
	return (stacks->stack_a);
}
