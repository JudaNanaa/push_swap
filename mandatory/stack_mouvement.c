/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:00:31 by madamou           #+#    #+#             */
/*   Updated: 2024/10/06 18:08:00 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"
#include <unistd.h>

void	ft_swap_a(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (stacks->len.a <= 1)
		return ;
	first = stacks->stack_a;
	second = stacks->stack_a->next;
	third = stacks->stack_a->next->next;
	second->next = first;
	first->next = third;
	second->prev = NULL;
	first->prev = second;
	third->prev = first;
	stacks->stack_a = second;
	stacks->first_a = second;
	ft_write(1, "sa\n", 3);
}

void	ft_swap_b(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (stacks->len.b <= 1)
		return ;
	first = stacks->stack_b;
	second = stacks->stack_b->next;
	third = stacks->stack_b->next->next;
	second->next = first;
	first->next = third;
	second->prev = NULL;
	first->prev = second;
	third->prev = first;
	stacks->stack_b = second;
	stacks->first_b = second;
	ft_write(1, "sb\n", 3);
}

void	ft_ra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;

	if (stacks->len.a <= 1)
		return ;
	first = stacks->stack_a;
	second = stacks->stack_a->next;
	stacks->last_a->next = first;
	first->next = NULL;
	second->prev = NULL;
	first->prev = stacks->last_a;
	stacks->last_a = first;
	stacks->first_a = second;
	stacks->stack_a = second;
}

void	ft_rotate_a(t_stacks *stacks, int cas)
{
	ft_ra(stacks);
	if (cas == 1)
		ft_stock_movement("ra\n", 1, stacks);
	if (cas == 2)
		ft_write(STDOUT_FILENO, "ra\n", 3);
}

void	ft_rb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;

	if (stacks->len.b <= 1)
		return ;
	first = stacks->stack_b;
	second = stacks->stack_b->next;
	stacks->last_b->next = first;
	first->next = NULL;
	second->prev = NULL;
	first->prev = stacks->last_b;
	stacks->last_b = first;
	stacks->first_b = second;
	stacks->stack_b = second;
}

void	ft_rotate_b(t_stacks *stacks, int cas)
{
	ft_rb(stacks);
	if (cas == 1)
		ft_stock_movement("rb\n", 1, stacks);
	if (cas == 2)
		ft_write(STDOUT_FILENO, "rb\n", 3);
		
}

void ft_db_rotate(t_stacks *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	ft_write(STDOUT_FILENO, "rr\n", 3);
}