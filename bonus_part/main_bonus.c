/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:36:54 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:37:02 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include <unistd.h>

t_stacks	*ft_line_by_line(t_stacks *st)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		st = ft_execute_prompt(line, st);
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
			return (ft_free_args(args), write(2, "Error\n", 6), 0);
		stacks = ft_args_to_stack(args);
		ft_line_by_line(stacks);
		if (!ft_check_if_sort(stacks->stack_a, stacks->stack_b))
		{
			(ft_clear_stack(stacks->stack_a), ft_clear_stack(stacks->stack_b));
			return (free(stacks), write(1, "KO\n", 3), 0);
		}
		else
		{
			ft_clear_stack(stacks->stack_a);
			return (write(1, "OK\n", 3), free(stacks), 0);
		}
	}
	return (write(1, "Error\n", 6), 1);
}
