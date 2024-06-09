/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:56:17 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:35:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_2_numbers(t_stacks *stacks)
{
	if (stacks->stack_a->nb > stacks->stack_a->next->nb)
	{
		stacks->stack_a = ft_swap_a(stacks);
		return (stacks->stack_a);
	}
	return (stacks->stack_a);
}
