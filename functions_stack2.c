/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:38:17 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 20:17:40 by madamou          ###   ########.fr       */
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
	int		buff;
	int		index;
	t_stack	*tmp;

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

t_stack	*ft_del_up_stack(t_stack *stack)
{
	t_stack	*buff;

	if (!stack)
		return (NULL);
	buff = stack;
	buff = buff->next;
	free(stack);
	return (buff);
}

int	ft_find_pivot(t_stack *stack, int len_stack)
{
	int	tab[100000];
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
		pivot = result[((len_stack - 1) / 2)];
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

int	ft_min(t_stack *stack_a)
{
	int	buff;

	buff = stack_a->nb;
	while (stack_a)
	{
		if (buff > stack_a->nb)
			buff = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (buff);
}

int	ft_max(t_stack *stack_a)
{
	int	buff;

	buff = stack_a->nb;
	while (stack_a)
	{
		if (buff < stack_a->nb)
			buff = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (buff);
}

t_stacks	*ft_pa_ra_or_rra(t_stacks *imad,int len_stackb, int len_stacka)
{
	int				nb;
	int buff;

	nb = ft_less_movement(imad->stack_a, imad->stack_b, len_stackb, len_stacka);
	if (ft_find_nb(imad->stack_b, nb) <= (len_stackb / 2))
	{
		while (imad->stack_b->nb != nb)
			imad->stack_b = ft_rotate_b(imad->stack_b, 1);
	}
	else
	{
			while (imad->stack_b->nb != nb)
			imad->stack_b = ft_rev_rotate_b(imad->stack_b, 1);
	}
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

int ft_less(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int ft_less_movement(t_stack *stack_a, t_stack *stack_b, int len_stackb, int len_stacka)
{
	int tab[99999];
	int tab_nb[99999];
	int i;
	int j;

	j = 0;
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

int ft_find_nb(t_stack *stack, int nb)
{
	int index;

	index = 0;
	while (stack->nb != nb)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int ft_find_nb_stacka(t_stack * stack_a, int nb)
{
	int index;
	int next;

	index = 0;
	next = ft_find_next(stack_a, nb);
	while (stack_a && stack_a->nb != next)
	{
		stack_a = stack_a->next;
		index++;
	}
	return (index);
}

int ft_find_next(t_stack *stack, int nb)
{
	int buff;
	int min;

	buff = nb;
	min = stack->nb;
	while (stack)
	{
		if (nb < stack->nb)
		{
			if (buff == nb)
				buff = stack->nb;
			else
				buff = ft_less(buff, stack->nb);
		}
		if (min > stack->nb)
			min = stack->nb;
		stack = stack->next;
	}
	if (buff == nb)
		return (min);
	return (buff);
}