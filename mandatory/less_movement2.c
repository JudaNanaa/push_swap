/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_movement2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:39:41 by madamou           #+#    #+#             */
/*   Updated: 2024/10/05 15:41:05 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	ft_find_next(t_stack *stack, int nb)
{
	int	buff;
	int	min;

	buff = nb;
	min = stack->nb;
	while (stack)
	{
		if (nb < stack->nb)
		{
			if (buff == nb)
				buff = stack->nb;
			else
				buff = ft_min(buff, stack->nb);
		}
		if (min > stack->nb)
			min = stack->nb;
		stack = stack->next;
	}
	if (buff == nb)
		return (min);
	return (buff);
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
