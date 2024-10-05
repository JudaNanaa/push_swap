/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:56:17 by madamou           #+#    #+#             */
/*   Updated: 2024/10/05 15:39:50 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_2_numbers(t_stacks *stacks)
{
	if (stacks->stack_a->nb > stacks->stack_a->next->nb)
		ft_swap_a(stacks);
}
