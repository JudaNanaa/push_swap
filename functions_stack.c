/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:40:57 by madamou           #+#    #+#             */
/*   Updated: 2024/04/27 20:27:13 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_bool	ft_is_empty_stack(t_stack *st)
{
	if (st == NULL)
		return (true);
	return (false);
}

t_stack	*ft_push_stack(t_stack *st, int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
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

void	ft_print_stack(t_stack *st)
{
	if (ft_is_empty_stack(st))
	{
		ft_printf("rien a afficher la pile est vide");
		return ;
	}
	while (st)
	{
		ft_printf("%d\n", st->nb);
		st = st->next;
	}
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
