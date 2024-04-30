/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:10:37 by madamou           #+#    #+#             */
/*   Updated: 2024/04/30 14:43:57 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*st;

	if (argc == 1)
		return (0);
	if (ft_check_args(argv))
	{
		ft_print_mouvements(0);
		st = ft_args_to_stack(argv);
		if (ft_check_if_sort(st, NULL))
			return (ft_clear_stack(st), 0);
		st = ft_push_swap(st);
		// ft_print_mouvements(2);
		// ft_print_stack(st);
		return (ft_clear_stack(st), 0);
	}
	return (ft_printf("Error\n"), 0);
}
