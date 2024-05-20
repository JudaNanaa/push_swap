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

t_stacks	*ft_line_by_line(char *line, t_stacks *st)
{
	while (line)
	{
		st = ft_execute_prompt(line, st);
		line = get_next_line(-1);
	}
	return (st);
}

int	main(int argc, char **argv)
{
	t_stacks	*st;
	char		*line;

	if (argc == 1)
		return (0);
	argv = ft_check_args(argv);
	if (argv)
	{
		if (!argv[0])
			return (0);
		st = ft_args_to_stack(argv);
		line = get_next_line(0);
		ft_line_by_line(line, st);
		if (!ft_check_if_sort(st->stack_a, st->stack_b))
		{
			ft_clear_stack(st->stack_a);
			return (ft_clear_stack(st->stack_b), write(1, "KO\n", 3), 0);
		}
		else
			return (write(1, "OK\n", 3), ft_clear_stack(st->stack_a), 0);
	}
	return (ft_printf("Error\n"), 1);
}
