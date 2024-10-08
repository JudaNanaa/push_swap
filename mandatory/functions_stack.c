/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:40:57 by madamou           #+#    #+#             */
/*   Updated: 2024/10/06 17:51:47 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

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
	{
		ft_clear_stack(st);
		return (NULL);
	}
	new->nb = nb;
	new->prev = NULL;
	new->next = st;
	if (st)
		st->prev = new;
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
