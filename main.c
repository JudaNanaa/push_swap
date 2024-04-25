/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:10:37 by madamou           #+#    #+#             */
/*   Updated: 2024/04/24 07:12:00 by madamou          ###   ########.fr       */
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
		st = ft_args_to_stack(argv);
		st = ft_all_stacks(st);
		ft_print_stack(st);
		return (ft_clear_stack(st), 0);
	}
	return (ft_printf("Error\n"), 0);
}
