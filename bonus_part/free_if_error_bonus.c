/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_if_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:11:31 by madamou           #+#    #+#             */
/*   Updated: 2024/05/16 18:36:54 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_free_error(t_stacks *st)
{
	ft_clear_stack(st->stack_a);
	ft_clear_stack(st->stack_b);
	ft_printf("Error\n");
	exit(EXIT_SUCCESS);
}
