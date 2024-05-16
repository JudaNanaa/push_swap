/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:38:17 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:35:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_bool	ft_check_if_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	buffer;

	if (ft_is_empty_stack(stack_b) == false)
		return (false);
	buffer = stack_a->nb;
	while (stack_a)
	{
		if (buffer > stack_a->nb)
			return (false);
		buffer = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (true);
}

t_stack	*ft_del_up_stack(t_stack *stack)
{
	t_stack	*buff;

	if (!stack)
		return (NULL);
	buff = stack;
	buff = buff->next;
	free(stack);
	return (buff);
}
