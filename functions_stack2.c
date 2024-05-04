/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:38:17 by madamou           #+#    #+#             */
/*   Updated: 2024/05/02 21:26:08 by madamou          ###   ########.fr       */
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

int ft_min(t_stack *stack_a)
{
	int buff;

	buff = stack_a->nb;
	while (stack_a)
	{
		if (buff > stack_a->nb)
			buff = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (buff);
}

int ft_max(t_stack *stack_a)
{
	int buff;

	buff = stack_a->nb;
	while (stack_a)
	{
		if (buff < stack_a->nb)
			buff = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (buff);
}

int ft_between(t_stack *stack_a, int nb)
{
	int buff;

	buff = stack_a->nb;
	while (stack_a->next)
		stack_a = stack_a->next;
	if (stack_a->nb < nb && nb < buff)
		return (1);
	return (0);
}

int ft_compter1(t_stack *stack_a, int nb, int cpt1)
{
	int buff;

	while (ft_between(stack_a, nb) == 0)
	{
		stack_a = ft_rotate_a(stack_a, 2);
		cpt1++;
	}
	buff = cpt1;
	while (buff-- > 0)
		stack_a = ft_rev_rotate_a(stack_a, 2);
	return (cpt1);
}

int ft_compter2(t_stack *stack_a, int nb, int cpt2)
{
	int buff;

	while (ft_between(stack_a, nb) == 0)
	{
		stack_a = ft_rev_rotate_a(stack_a, 2);
		cpt2++;
	}
	buff = cpt2;
	while (buff-- > 0)
		stack_a = ft_rotate_a(stack_a, 2);
	return (cpt2);
}

t_stack *ft_pa_ra_or_rra(t_stack *stack_a, t_stack *stack_b, int cas)
{
	int nb;
	static t_stack *stat;

	nb = stack_b->nb;
	if (cas == 2)
		return (stat);
	if (ft_compter1(stack_a, nb, 0) < ft_compter2(stack_a, nb, 0))
	{
		nb = ft_compter1(stack_a, nb, 0);
		while (nb-- > 0)
			stack_a = ft_rotate_a(stack_a, 1);
	}
	else
	{
		nb = ft_compter2(stack_a, nb, 0);
		while (nb-- > 0)
			stack_a = ft_rev_rotate_a(stack_a, 1);
	}
	stack_a = ft_push_a(stack_a, stack_b, 1);
	stat = ft_push_a(stack_a, stack_b, 2);
	return (stack_a);
}
