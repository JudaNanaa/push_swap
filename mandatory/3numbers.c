/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:32:57 by madamou           #+#    #+#             */
/*   Updated: 2024/10/05 15:40:02 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_if_3_numbers(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->stack_a->nb;
	second = stacks->stack_a->next->nb;
	third = stacks->stack_a->next->next->nb;
	if (first < second && second < third)
		return ;
	if (first > second && first > third)
		ft_rotate_a(stacks, 1);
	else if (second > first && second > third)
		ft_rev_rotate_a(stacks, 1);
	else
		ft_swap_a(stacks);
	ft_if_3_numbers(stacks);
}
