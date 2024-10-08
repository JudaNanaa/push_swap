/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:39:11 by madamou           #+#    #+#             */
/*   Updated: 2024/10/06 17:49:33 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

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

t_stack	*ft_args_to_stack(char **argv, int index)
{
	t_stack	*st;

	st = NULL;
	while (index-- - 1 >= 0)
	{
		st = ft_push_stack(st, ft_atoi(argv[index]));
		if (!st)
		{
			ft_free_args(argv);
			return (NULL);
		}
	}
	return (argv = ft_free_args(argv), st);
}
