/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:36:54 by madamou           #+#    #+#             */
/*   Updated: 2024/08/28 21:54:22 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include <unistd.h>

int	ft_write(int fd, char *str, size_t len)
{
	int	print;

	print = write(fd, str, len);
	if (print == -1)
		return (-1);
	return (0);
}

t_stacks	*ft_line_by_line(t_stacks *st)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		st = ft_execute_prompt(line, st);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (st);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;

	if (argc == 1)
		return (0);
	args = ft_check_args(argv);
	if (args)
	{
		if (!args[0])
			return (ft_free_args(args), ft_write(2, "Error\n", 6));
		stacks = ft_args_to_stack(args);
		ft_line_by_line(stacks);
		if (!ft_check_if_sort(stacks->stack_a, stacks->stack_b))
		{
			(ft_clear_stack(stacks->stack_a), ft_clear_stack(stacks->stack_b));
			return (free(stacks), ft_write(1, "KO\n", 3));
		}
		else
		{
			ft_clear_stack(stacks->stack_a);
			return (ft_write(1, "OK\n", 3), free(stacks), 0);
		}
	}
	return (ft_write(2, "Error\n", 6), 1);
}
