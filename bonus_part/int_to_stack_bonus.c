/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:39:11 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 17:38:02 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

t_stack	*ft_args_to_stack(char **argv)
{
	int		index;
	t_stack	*st;

	st = NULL;
	index = 0;
	while (argv[index])
		index++;
	while (index-- - 1 >= 0)
	{
		st = ft_push_stack(st, ft_atoi(argv[index]));
		if (!st)
		{
			ft_free_args(argv);
			exit(EXIT_FAILURE);
		}
	}
	return (argv = ft_free_args(argv), st);
}
