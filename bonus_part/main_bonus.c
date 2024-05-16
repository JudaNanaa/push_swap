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

int	main(int argc, char **argv)
{
	t_stacks	*st;
	char		*line;

	if (argc == 1)
		return (0);
	argv = ft_check_args(argv);
	if (argv)
	{
		st = ft_args_to_stack(argv);
		line = get_next_line(0);
		while (line)
		{
			st = ft_execute_prompt(line, st);
			line = get_next_line(0);
		}
		if (!ft_check_if_sort(st->stack_a, st->stack_b))
		{
			ft_clear_stack(st->stack_b);
			return (ft_clear_stack(st->stack_b), ft_printf("KO\n"), 0);
		}
		else
			return (ft_printf("OK\n"), ft_clear_stack(st->stack_a), 0);
	}
	return (ft_printf("Error\n"), 1);
}
