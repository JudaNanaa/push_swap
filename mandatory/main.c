/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:10:37 by madamou           #+#    #+#             */
/*   Updated: 2024/08/28 21:54:14 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	ft_write(int fd, char *str, size_t len)
{
	int	print;

	print = write(fd, str, len);
	if (print == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*st;
	char	**args;

	if (argc == 1)
		return (0);
	args = ft_check_args(argv);
	if (args)
	{
		if (!args[0])
			return (ft_free_args(args), ft_write(2, "Error\n", 2));
		st = ft_args_to_stack(args);
		if (!st)
			return (ft_write(2, "Error\n", 6));
		if (ft_check_if_sort(st, NULL))
			return (ft_clear_stack(st), 0);
		st = ft_push_swap(st);
		return (ft_clear_stack(st), 0);
	}
	return (ft_write(2, "Error\n", 6));
}
