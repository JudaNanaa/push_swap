/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:38:17 by madamou           #+#    #+#             */
/*   Updated: 2024/04/25 20:55:43 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

bool ft_check_if_sort(t_stack **stack)
{
	int buffer;
	t_stack *tmp;

	tmp = stack[stacka];
	if (ft_is_empty_stack(stack[stackb]) == false)
		return (false);
	buffer = tmp->nb;
	while (tmp)
	{
		if (buffer > tmp->nb)
			return (false);
		buffer = tmp->nb;
		tmp = tmp->next;
	}
	return (true);
}