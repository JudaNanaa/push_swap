/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:37:19 by madamou           #+#    #+#             */
/*   Updated: 2024/10/08 00:54:40 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_find_pivot(t_stack *stack, int len_stack, int *pivot)
{
	int	tab[10000];
	int	i;

	i = 0;
	while (i < len_stack)
	{
		tab[i++] = stack->nb;
		stack = stack->next;
	}
	ft_sort_tab(tab, i);
	if (len_stack == 4)
	{
		pivot[0] = tab[0];
		pivot[1] = tab[0];
	}
	else
	{
		pivot[0] = tab[((len_stack - 1) / 4)];
		pivot[3] = tab[((len_stack - 1) / 4) / 2];
		pivot[1] = tab[((len_stack - 1) / 2)];
		pivot[2] = tab[(((len_stack - 1) * 3) / 4)];
	}
}

int	ft_find_un_quart(t_stack *stack, int len_stack)
{
	int	tab[10000];
	int	i;
	int	*result;
	int	pivot;

	i = 0;
	while (i < len_stack)
	{
		tab[i++] = stack->nb;
		stack = stack->next;
	}
	result = ft_sort_tab(tab, i);
	if (len_stack == 4)
		pivot = result[0];
	else
		pivot = result[((len_stack - 1) / 4)];
	return (pivot);
}

int	ft_find_trois_quart(t_stack *stack, int len_stack)
{
	int	tab[10000];
	int	i;
	int	*result;
	int	pivot;

	i = 0;
	while (i < len_stack)
	{
		tab[i++] = stack->nb;
		stack = stack->next;
	}
	result = ft_sort_tab(tab, i);
	if (len_stack == 4)
		pivot = result[0];
	else
		pivot = result[(((len_stack - 1) * 3) / 4)];
	return (pivot);
}

int	*ft_sort_tab(int *tab, int len_tab)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	while (i < len_tab)
	{
		j = i + 1;
		while (j < len_tab)
		{
			if (tab[i] > tab[j])
			{
				buff = tab[i];
				tab[i] = tab[j];
				tab[j] = buff;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
