/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:51 by madamou           #+#    #+#             */
/*   Updated: 2024/10/04 22:39:40 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_all_push_in_b(t_stacks *stacks, int len_stacka)
{
	int	trois_quart;
	int	un_quart;
	int	tmp;
	int	pivot;

	if (len_stacka == 3)
		return ;
	tmp = len_stacka;
	pivot = ft_find_pivot(stacks->stack_a, len_stacka);
	trois_quart = ft_find_trois_quart(stacks->stack_a, len_stacka);
	un_quart = ft_find_un_quart(stacks->stack_a, tmp);
	while (len_stacka > (tmp / 2) && len_stacka > 3)
	{
		stacks = ft_presort_stack_a_part1(stacks, pivot);
		stacks = ft_push_b(stacks);
		if (stacks->stack_b->nb >= trois_quart)
			stacks->stack_b = ft_rotate_b(stacks, 1);
		len_stacka--;
	}
	ft_all_push_in_b(stacks, len_stacka);
}

void	ft_final_sort(t_stacks *stacks)
{
	int	pivot;

	pivot = ft_find_pivot(stacks->stack_a, ft_len_stack(stacks->stack_a));
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
}

t_stack	*ft_push_swap(t_stack *stack_a)
{
	int			len_stack;
	int			i;
	t_stacks	stacks;

	stacks.stack_a = stack_a;
	stacks.stack_b = NULL;
	len_stack = ft_len_stack(stacks.stack_a);
	if (len_stack == 2)
		return (stack_a = ft_2_numbers(&stacks), stack_a);
	if (len_stack > 5)
		ft_all_push_in_b(&stacks, len_stack);
	else
	{
		i = len_stack;
		while (i-- > 3)
			ft_push_b(&stacks);
	}
	stacks.stack_a = ft_if_3_numbers(&stacks);
	i = 2;
	while (++i < len_stack)
		ft_pa_ra_or_rra(&stacks, len_stack - i, i);
	ft_final_sort(&stacks);
	return (stacks.stack_a);
}
