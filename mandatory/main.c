/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:10:37 by madamou           #+#    #+#             */
/*   Updated: 2024/05/20 16:57:12 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*st;
	char	**imad;

	if (argc == 1)
		return (0);
	imad = ft_check_args(argv);
	if (imad)
	{
		if (!imad[0])
		{
			ft_free_args(imad);
			return (0);
		}
		st = ft_args_to_stack(imad);
		if (!st)
			return (write(2, "Error\n", 6), 0);
		if (ft_check_if_sort(st, NULL))
			return (ft_clear_stack(st), 0);
		st = ft_push_swap(st);
		return (ft_clear_stack(st), 0);
	}
	return (write(2, "Error\n", 6), 0);
}
