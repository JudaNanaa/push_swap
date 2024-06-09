/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:51 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:35:54 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stacks	*ft_hundred_or_bellow(t_stacks *stacks, int pivot, int len_stacka)
{
	while (len_stacka-- > 3)
	{
		(void)pivot;
		stacks = ft_push_b(stacks);
		if (stacks->stack_b->nb > pivot)
			stacks->stack_b = ft_rotate_b(stacks, 1);
	}
	return (stacks);
}

t_stacks	*ft_all_push_in_b(t_stacks *stacks, int pivot, int len_stacka)
{
	int	trois_quart;
	int	un_quart;
	int	tmp;

	tmp = len_stacka;
	trois_quart = ft_find_trois_quart(stacks->stack_a, len_stacka);
	un_quart = ft_find_un_quart(stacks->stack_a, tmp);
	while (len_stacka > (tmp / 2) - 1 && len_stacka > 5)
	{
		stacks = ft_presort_stack_a_part1(stacks, pivot);
		stacks = ft_push_b(stacks);
		if (stacks->stack_b->nb >= trois_quart)
			stacks->stack_b = ft_rotate_b(stacks, 1);
		len_stacka--;
	}
	while (len_stacka > (tmp / 4) - 1 && len_stacka > 5)
	{
		stacks = ft_presort_stack_a_part2(stacks, un_quart);
		stacks = ft_push_b(stacks);
		len_stacka--;
	}
	while (len_stacka-- > 3)
		stacks = ft_push_b(stacks);
	return (stacks);
}

t_stacks	*ft_final_sort(t_stacks *stacks, int pivot)
{
	if (stacks->stack_a->nb > pivot)
	{
		while (!ft_check_if_sort(stacks->stack_a, stacks->stack_b))
			stacks->stack_a = ft_rotate_a(stacks, 1);
		ft_stock_movement("", 2, stacks);
	}
	else
	{
		while (!ft_check_if_sort(stacks->stack_a, stacks->stack_b))
			stacks->stack_a = ft_rev_rotate_a(stacks, 1);
		ft_stock_movement("", 2, stacks);
	}
	return (stacks);
}

t_stack	*ft_push_swap(t_stack *stack_a)
{
	int			len_stack;
	int			pivot;
	int			i;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (ft_clear_stack(stack_a), NULL);
	stacks->stack_a = stack_a;
	stacks->stack_b = NULL;
	len_stack = ft_len_stack(stacks->stack_a);
	pivot = ft_find_pivot(stacks->stack_a, len_stack);
	if (len_stack == 2)
		return (stack_a = ft_2_numbers(stacks), free(stacks), stack_a);
	stacks = ft_all_push_in_b(stacks, pivot, len_stack);
	stacks->stack_a = ft_if_3_numbers(stacks);
	i = 2;
	while (++i < len_stack)
		stacks = ft_pa_ra_or_rra(stacks, len_stack - i, i);
	stacks = ft_final_sort(stacks, pivot);
	return (stack_a = stacks->stack_a, free(stacks), stack_a);
}
