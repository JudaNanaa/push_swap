/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:40:57 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:36:56 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	ft_is_empty_stack(t_stack *st)
{
	if (st == NULL)
		return (1);
	return (0);
}

t_stack	*ft_push_stack(t_stack *st, int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (ft_clear_stack(st), NULL);
	new->nb = nb;
	new->next = st;
	return (new);
}

t_stack	*ft_clear_stack(t_stack *st)
{
	t_stack	*buff;

	if (ft_is_empty_stack(st))
		return (NULL);
	buff = st->next;
	free(st);
	return (ft_clear_stack(buff));
}

int	ft_len_stack(t_stack *st)
{
	int	i;

	i = 0;
	while (st)
	{
		st = st->next;
		i++;
	}
	return (i);
}

int	ft_check_if_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	buffer;

	if (ft_is_empty_stack(stack_b) == 0)
		return (0);
	buffer = stack_a->nb;
	while (stack_a)
	{
		if (buffer > stack_a->nb)
			return (0);
		buffer = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (1);
}
