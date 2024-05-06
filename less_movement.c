/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:38:52 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 22:57:04 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stacks	*ft_pa_ra_or_rra(t_stacks *imad, int len_stackb, int len_stacka)
{
	int	nb;
	int	buff;

	nb = ft_less_movement(imad->stack_a, imad->stack_b, len_stackb, len_stacka);
	imad = ft_place_top_b(imad, nb, len_stackb);
	buff = ft_find_nb_stacka(imad->stack_a, nb);
	nb = len_stacka - buff;
	if (buff <= nb)
	{
		while (buff-- > 0)
			imad->stack_a = ft_rotate_a(imad->stack_a, 1);
	}
	else
	{
		while (nb-- > 0)
			imad->stack_a = ft_rev_rotate_a(imad->stack_a, 1);
	}
	imad->stack_a = ft_push_a(imad->stack_a, imad->stack_b, 1);
	imad->stack_b = ft_push_a(imad->stack_a, imad->stack_b, 2);
	return (imad);
}

int	ft_less(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_less_movement(t_stack *stack_a, t_stack *stack_b, int len_stackb,
		int len_stacka)
{
	int	*tab;
	int	test[99999];
	int	tab_nb[99999];
	int	i;
	int	j;

	j = 0;
	tab = ft_less_movement_in_b(test, len_stackb);
	while (j < len_stackb)
	{
		i = ft_find_nb_stacka(stack_a, stack_b->nb);
		tab[j] += ft_less(i, len_stacka - i);
		tab_nb[j++] = stack_b->nb;
		stack_b = stack_b->next;
	}
	j = 0;
	i = 0;
	while (j < len_stackb)
	{
		if (tab[i] > tab[j])
			i = j;
		j++;
	}
	return (tab_nb[i]);
}

int	ft_find_nb(t_stack *stack, int nb)
{
	int	index;

	index = 0;
	while (stack->nb != nb)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	ft_find_nb_stacka(t_stack *stack_a, int nb)
{
	int	index;
	int	next;

	index = 0;
	next = ft_find_next(stack_a, nb);
	while (stack_a && stack_a->nb != next)
	{
		stack_a = stack_a->next;
		index++;
	}
	return (index);
}
