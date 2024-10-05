/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_to_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:23:49 by itahri            #+#    #+#             */
/*   Updated: 2024/10/05 15:08:47 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stacks	*ft_presort_stack_a_part1(t_stacks *stacks, int pivot)
{
	while (stacks->stack_a->nb > pivot)
		ft_rotate_a(stacks, 1);
	return (stacks);
}

t_stacks	*ft_presort_stack_a_part2(t_stacks *stacks, int un_quart)
{
	while (stacks->stack_a->nb < un_quart)
		ft_rotate_a(stacks, 1);
	return (stacks);
}
