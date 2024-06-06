/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:33:21 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:36:51 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_stacks	*ft_check_swap(char *line, t_stacks *st)
{
	if (ft_strcmp(line, "sa\n") == 0)
		st->stack_a = ft_swap_a(st->stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		st->stack_b = ft_swap_b(st->stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		st->stack_a = ft_swap_a(st->stack_a);
		st->stack_b = ft_swap_b(st->stack_b);
	}
	return (st);
}

t_stacks	*ft_check_rotate(char *line, t_stacks *st)
{
	if (ft_strcmp(line, "ra\n") == 0)
		st->stack_a = ft_rotate_a(st->stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		st->stack_b = ft_rotate_b(st->stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		st->stack_a = ft_rotate_a(st->stack_a);
		st->stack_b = ft_rotate_b(st->stack_b);
	}
	return (st);
}

t_stacks	*ft_check_rev_rotate(char *line, t_stacks *st)
{
	if (ft_strcmp(line, "rra\n") == 0)
		st->stack_a = ft_rev_rotate_a(st->stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		st->stack_b = ft_rev_rotate_b(st->stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		st->stack_a = ft_rev_rotate_a(st->stack_a);
		st->stack_b = ft_rev_rotate_b(st->stack_b);
	}
	return (st);
}

t_stacks	*ft_execute_prompt(char *line, t_stacks *st)
{
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n") || !ft_strcmp(line,
			"ss\n"))
		st = ft_check_swap(line, st);
	else if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "rr\n"))
		st = ft_check_rotate(line, st);
	else if (!ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"))
		st = ft_check_rev_rotate(line, st);
	else if (ft_strcmp(line, "pa\n") == 0)
		st = ft_push_a(st);
	else if (ft_strcmp(line, "pb\n") == 0)
		st = ft_push_b(st);
	else
	{
		write(1, "Error\n", 6);
		free(line);
		ft_free_error(st);
	}
	return (st);
}
