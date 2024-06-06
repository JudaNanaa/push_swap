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

t_stacks	*ft_line_by_line(char *line, t_stacks *st)
{
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
	char		*line;
	char		**args;

	if (argc == 1)
		return (0);
	args = ft_check_args(argv);
	if (args)
	{
		if (!args[0])
			return (0);
		stacks = ft_args_to_stack(args);
		line = get_next_line(0);
		ft_line_by_line(line, stacks);
		if (!ft_check_if_sort(stacks->stack_a, stacks->stack_b))
		{
			ft_clear_stack(stacks->stack_a);
			return (ft_clear_stack(stacks->stack_b), write(1, "KO\n", 3), 0);
		}
		else
			return (write(1, "OK\n", 3), ft_clear_stack(stacks->stack_a), 0);
	}
	return (ft_printf("Error\n"), 1);
}
