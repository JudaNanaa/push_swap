/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:39:11 by madamou           #+#    #+#             */
/*   Updated: 2024/05/09 00:29:14 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**ft_free_args(char **argv)
{
	int	index;

	index = 0;
	while (argv[index])
		free(argv[index++]);
	free(argv);
	argv = NULL;
	return (argv);
}

t_stacks	*ft_args_to_stack(char **argv)
{
	int			index;
	t_stacks	*st;

	st = malloc(sizeof(t_stacks));
	if (!st)
		return (argv = ft_free_args(argv), NULL);
	st->stack_a = NULL;
	st->stack_b = NULL;
	index = 0;
	while (argv[index])
		index++;
	while (index-- - 1 >= 0)
	{
		st->stack_a = ft_push_stack(st->stack_a, ft_atoi(argv[index]));
		if (!st->stack_a)
		{
			ft_free_args(argv);
			exit(EXIT_FAILURE);
		}
	}
	return (argv = ft_free_args(argv), st);
}
