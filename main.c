/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:10:37 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 20:45:55 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*st;
	char **imad;

	if (argc == 1)
		return (0);
	imad = ft_check_args(argv);
	if (imad)
	{
		st = ft_args_to_stack(imad);
		// ft_stock_movements("rrb\n", 0);
		if (ft_check_if_sort(st, NULL))
			return (ft_clear_stack(st), 0);
		st = ft_push_swap(st);
		// ft_stock_movements("rrb\n", 2);
		return (ft_clear_stack(st), 0);
	}
	return (write(2, "Error\n", 6), 0);
}
