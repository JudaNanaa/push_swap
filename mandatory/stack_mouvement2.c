/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:15:01 by madamou           #+#    #+#             */
/*   Updated: 2024/10/06 19:47:57 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"
#include <time.h>

void	ft_rra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->len.a <= 1)
		return ;
	first = stacks->stack_a;
	last = stacks->last_a;
	before_last = stacks->last_a->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	before_last->next = NULL;
	stacks->first_a = last;
	stacks->stack_a = last;
	stacks->last_a = before_last;
}


void	ft_rev_rotate_a(t_stacks *stacks, int cas)
{
	ft_rra(stacks);
	if (cas == 1)
		ft_stock_movement("rra\n", 1, stacks);
	if (cas == 2)
		ft_write(STDOUT_FILENO, "rra\n", 4);
}

void	ft_rrb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->len.b <= 1)
		return ;
	first = stacks->stack_b;
	last = stacks->last_b;
	before_last = stacks->last_b->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	before_last->next = NULL;
	stacks->first_b = last;
	stacks->stack_b = last;
	stacks->last_b = before_last;
}


void	ft_rev_rotate_b(t_stacks *stacks, int cas)
{
	ft_rrb(stacks);
	if (cas == 1)
		ft_stock_movement("rrb\n", 1, stacks);
	if (cas == 2)
		ft_write(STDOUT_FILENO, "rrb\n", 4);
}

void	ft_db_rev_rotate(t_stacks *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	ft_write(STDOUT_FILENO, "rrr\n", 4);
	
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack	*first_b;
	t_stack	*second_b;

	first_b = stacks->stack_b;
	second_b = stacks->stack_b->next;
	first_b->next = stacks->stack_a;
	if (stacks->stack_a)
		stacks->stack_a->prev = first_b;
	stacks->stack_a = first_b;
	stacks->first_a = first_b;
	stacks->stack_b = second_b;
	stacks->first_b = second_b;
	if (second_b)
		second_b->prev = NULL;
	if (!stacks->last_a)
		stacks->last_a = first_b;
	++stacks->len.a;
	--stacks->len.b;
	ft_stock_movement("", 2, stacks);
	ft_write(1, "pa\n", 3);
}


void	ft_push_b(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*second_a;

	first_a = stacks->stack_a;
	second_a = stacks->stack_a->next;
	first_a->next = stacks->stack_b;
	if (stacks->stack_b)
		stacks->stack_b->prev = first_a;
	stacks->stack_b = first_a;
	stacks->first_b = first_a;
	stacks->stack_a = second_a;
	stacks->first_a = second_a;
	if (second_a)
		second_a->prev = NULL;
	if (!stacks->last_b)
		stacks->last_b = first_a;
	--stacks->len.a;
	++stacks->len.b;
	ft_stock_movement("", 2, stacks);
	ft_write(1, "pb\n", 3);
}

