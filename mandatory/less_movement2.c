/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_movement2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:39:41 by madamou           #+#    #+#             */
/*   Updated: 2024/10/06 03:21:44 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	ft_find_next(t_stack *stack, int nb)
{
	int	buff[2];
	int	min[2];
	int index;

	index = 0;
	buff[0] = nb;
	buff[1] = 0;
	min[0] = stack->nb;
	min[1] = 0;
	while (stack)
	{
		if (nb < stack->nb && (buff[0] == nb || buff[0] > stack->nb))
		{
			buff[0] = stack->nb;
			buff[1] = index;
			if (buff[0] == nb + 1)
				return (buff[1]);
		}
		if (min[0] > stack->nb)
		{
			min[0] = stack->nb;
			min[1] = index;
		}
		++index;
		stack = stack->next;
	}
	if (buff[0] == nb)
		return (min[1]);
	return (buff[1]);
}

void ft_less_movement_in_b(int *tab, int len_stackb)
{
	int	i;

	i = 0;
	while (i < len_stackb)
	{
		if (i <= (len_stackb / 2))
		{
			tab[i] = i;
			i++;
		}
		if (i > (len_stackb / 2))
		{
			tab[i] = len_stackb - i;
			i++;
		}
	}
}

t_stacks	*ft_place_top_b(t_stacks *stacks, int nb, int len_stackb)
{
	if (ft_find_nb(stacks->stack_b, nb) <= (len_stackb / 2))
	{
		while (stacks->stack_b->nb != nb)
			ft_rotate_b(stacks, 1);
	}
	else
	{
		while (stacks->stack_b->nb != nb)
			ft_rev_rotate_b(stacks, 1);
	}
	return (stacks);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
