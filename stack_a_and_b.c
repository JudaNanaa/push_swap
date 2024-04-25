/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_and_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:07:56 by madamou           #+#    #+#             */
/*   Updated: 2024/04/25 20:55:40 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack *ft_all_stacks(t_stack *stack_a)
{
	t_stack *stack_b;
	t_stack *tab[2];
	
	stack_b = NULL;
	tab[stacka] = stack_a;
	tab[stackb] = stack_b;
	if (ft_len_stack(tab[0]) == 2)
		tab[0] = ft_if_2_numbers(tab[0]);
	if (ft_len_stack(tab[0]) == 3)
		tab[0] = ft_if_2_numbers(tab[0]);
	if (ft_check_if_sort(tab) == true)
		ft_printf("c'est trop cool\n");
	return (tab[0]);
}
