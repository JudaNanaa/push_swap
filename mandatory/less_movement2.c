/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_movement2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:39:41 by madamou           #+#    #+#             */
/*   Updated: 2024/10/07 17:07:19 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

// Changer cette function pour avoir de meilleurs resultats
int	ft_find_next(t_stack *even, int nb)
{
	int	buff[2];
	int	min[2];
	int index;
	t_stack *odd;

	odd = even->next;
	index = 0;
	buff[0] = nb;
	buff[1] = 0;
	min[0] = even->nb;
	min[1] = 0;
	while (odd)
	{
		if (nb < even->nb && (buff[0] == nb || buff[0] > even->nb))
		{
			buff[0] = even->nb;
			buff[1] = index;
		}
		if (nb < odd->nb && (buff[0] == nb || buff[0] > odd->nb))
		{
			buff[0] = odd->nb;
			buff[1] = index + 1;
		}
		if (buff[0] == nb + 1)
			return (buff[1]);
		if (min[0] > ft_min(even->nb, odd->nb))
		{
			min[0] = ft_min(even->nb, odd->nb);
			if (min[0] == even->nb)
				min[1] = index;
			else
				min[1] = index + 1;
		}
		index += 2;
		even = odd->next;
		if (even == NULL)
			break;
		odd = even->next;
	}
	if (even)
	{
		if (nb < even->nb && (buff[0] == nb || buff[0] > even->nb))
		{
			buff[0] = even->nb;
			buff[1] = index;
			if (buff[0] == nb + 1)
				return (buff[1]);
		}	
		if (min[0] > even->nb)
		{
			min[0] = even->nb;
			min[1] = index;
		}	
	}
	if (buff[0] == nb)
		return (min[1]);
	return (buff[1]);
}

// int	ft_find_next_fork(t_stack *first, t_stack *last, int nb, int len)
// {
// 	int	buff[2];
// 	int	min[2];
// 	int index;

// 	index = 0;
// 	buff[0] = nb;
// 	buff[1] = 0;
// 	min[0] = first->nb;
// 	min[1] = 0;
// 	while (index <= len / 2)
// 	{
// 		if (nb < first->nb && (buff[0] == nb || buff[0] > first->nb))
// 		{
// 			buff[0] = first->nb;
// 			buff[1] = index;
// 		}
// 		if (nb < last->nb && (buff[0] == nb || buff[0] > last->nb))
// 		{
// 			buff[0] = last->nb;
// 			buff[1] = len - 1 - index;
// 		}
// 		if (buff[0] == nb + 1)
// 			return (buff[1]);
// 		if (min[0] > ft_min(first->nb, last->nb))
// 		{
// 			min[0] = ft_min(first->nb, last->nb);
// 			if (min[0] == first->nb)
// 				min[1] = index;
// 			else
// 			 	min[1] = len - 1 - index;
// 		}
// 		++index;
// 		first = first->next;
// 		last = last->prev;
// 	}
// 	if (buff[0] == nb)
// 		return (min[1]);
// 	return (buff[1]);
// }

int	ft_find_next_fork(t_stack *first, t_stack *last, int nb, int len)
{
	int	buff[2];
	int	min[2];
	int index;
	t_stack *even_first, *odd_first;
	t_stack *even_last, *odd_last;

	index = 0;
	buff[0] = nb;
	buff[1] = 0;
	min[0] = first->nb;
	min[1] = 0;
	even_first = first;
	odd_first = first->next;
	even_last = last;
	odd_last = last->prev;
	while (index <= len / 2)
	{
		if (nb < even_first->nb && (buff[0] == nb || buff[0] > even_first->nb))
		{
			buff[0] = even_first->nb;
			buff[1] = index;
		}
		if (nb < odd_first->nb && (buff[0] == nb || buff[0] > odd_first->nb))
		{
			buff[0] = odd_first->nb;
			buff[1] = index + 1;
		}
		if (nb < even_last->nb && (buff[0] == nb || buff[0] > even_last->nb))
		{
			buff[0] = even_last->nb;
			buff[1] = len - 1 - index;
		}
		if (nb < odd_last->nb && (buff[0] == nb || buff[0] > odd_last->nb))
		{
			buff[0] = odd_last->nb;
			buff[1] = len - 1 - index - 1;
		}
		if (buff[0] == nb + 1)
			return (buff[1]);
		if (min[0] > ft_min(ft_min(even_first->nb, odd_first->nb), ft_min(even_last->nb, odd_last->nb)))
		{
			min[0] = ft_min(ft_min(even_first->nb, odd_first->nb), ft_min(even_last->nb, odd_last->nb));
			if (min[0] == even_first->nb)
				min[1] = index;
			else if (min[0] == odd_first->nb)
				min[1] = index + 1;
			else if (min[0] == even_last->nb)
				min[1] = len - 1 - index;
			else
				min[1] = len - 1 - index - 1;
		}
		index += 2;
		even_first = odd_first->next;
		if (even_first)
			odd_first = even_first->next;
		even_last = odd_last->prev;
		if (even_last)
			odd_last = even_last->prev;
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
