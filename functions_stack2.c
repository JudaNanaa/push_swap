/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:38:17 by madamou           #+#    #+#             */
/*   Updated: 2024/04/30 11:16:18 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

t_bool	ft_check_if_sort_inverse(t_stack *stack_a, t_stack *stack_b)
{
	int	buffer;

	if (ft_is_empty_stack(stack_b) == false)
		return (false);
	buffer = stack_a->nb;
	while (stack_a)
	{
		if (buffer < stack_a->nb)
			return (false);
		buffer = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (true);
}

int	ft_find_biggest_nb(t_stack *stack_a, int pivot)
{
	int buff;
	int index;
	t_stack *tmp;

	tmp = stack_a;
	index = 1;
	buff = stack_a->nb;
	while (stack_a && buff > pivot)
	{
		if (stack_a->nb < buff)
			buff = stack_a->nb;
		stack_a = stack_a->next;
	}
	while (tmp->nb != buff)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	ft_find_biggest_nb_inverse(t_stack *stack_a, int pivot)
{
	int buff;
	int index;
	t_stack *tmp;

	tmp = stack_a;
	index = 1;
	buff = stack_a->nb;
	while (stack_a)
	{
		if (stack_a->nb <= pivot)
			buff = stack_a->nb;
		stack_a = stack_a->next;
	}
	while (tmp->nb != buff)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

t_stack *ft_del_up_stack(t_stack *stack)
{
	t_stack *buff;
	
	if (!stack)
		return (NULL);
	buff = stack;
	buff = buff->next;
	free(stack);
	return (buff);
}

void				ft_print_mouvements(int cas)
{
	static int nb;

	if (cas == 0)
		nb = 0;
	if (cas == 1)
		nb++;
	if (cas == 2)
		ft_printf("le nombre de mouvements est de: %d\n", nb);
}

int ft_find_pivot(t_stack *stack)
{
	int tab[100000];
	int len_stack;
	int i;
	int *result;
	int pivot;

	i = 0;
	len_stack = ft_len_stack(stack);
	while (i < len_stack)
	{
		tab[i++] = stack->nb;
		stack = stack->next;
	}
	result = ft_sort_tab(tab, i);
	if (len_stack == 4)
		pivot = result[0];
	else
		pivot = result[((len_stack - 1)/ 2)];
	return (pivot);
}

int *ft_sort_tab(int *tab, int len_tab)
{
	int i;
	int j;
	int buff;

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

int ft_normal_or_rev(t_stack *stack, int len_stack, int pivot)
{
	int index1;
	int index2;
	int tmp;

	index1 = 1;
	while (stack && (stack->nb > pivot))
	{
		stack = stack->next;
		index1++;
	}
	index2 = index1;
	tmp = index1;
	while (stack)
	{
		if (stack->nb <= pivot && (tmp >= (len_stack / 2) + 1))
			index2 = tmp;
		stack = stack->next;
		tmp++;
	}
	if ((len_stack / 2) + 1 < index2)
	{
		index2 += 2 + (len_stack - index2);
		index2 -= len_stack;
		if (index2 < index1)
			return (0);
	}
	return (1);
}
