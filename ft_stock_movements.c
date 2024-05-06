/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:03:50 by madamou           #+#    #+#             */
/*   Updated: 2024/05/06 00:46:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_stock_movements(char *move, int cas)
{
	static char *print;
	
	if (cas == 0)
	{
		print = malloc(sizeof(char));
		if (!print)
			return (0);
		print[0] = '\0';
	}
	if (cas == 1)
	{
		print = ft_realloc(print, ft_strlen(move));
		if (!print)
			return (0);
		print = ft_strcat(print, move);
	}
	if (cas == 2)
	{
		ft_format_print(print);
		free(print);
	}
	return (1);
}

int ft_format_print(char *print)
{
	char **str;
	int i;

	i = 0;
	str = ft_split(print, '\n');
	if (!str)
		return (0);
	
	while (str[i])
	{
		if ((!ft_strcmp(str[i], "ra") && (str[i + 1] && !ft_strcmp(str[i + 1], "rb")))
			|| (!ft_strcmp(str[i], "rb") && (str[i + 1] && !ft_strcmp(str[i + 1], "ra"))))
		{
			ft_printf("rr\n");
			i += 2;
		}
		if ((!ft_strcmp(str[i], "rra") && (str[i + 1] && !ft_strcmp(str[i + 1], "rrb")))
			|| (!ft_strcmp(str[i], "rrb") && !ft_strcmp(str[i + 1], "rra")))
		{
			ft_printf("rrr\n");
			i += 2;
		}
		if ((!ft_strcmp(str[i], "ra") && (str[i + 1] && !ft_strcmp(str[i + 1], "rra")))
			|| (!ft_strcmp(str[i], "rra") && (str[i + 1] && !ft_strcmp(str[i + 1], "ra"))))
			i += 2;
		if ((!ft_strcmp(str[i], "rb") &&(str[i + 1] && !ft_strcmp(str[i + 1], "rrb")))
			|| (!ft_strcmp(str[i], "rrb") && (str[i + 1] && !ft_strcmp(str[i + 1], "rb"))))
			i += 2;
		if ((!ft_strcmp(str[i], "pb") && (str[i + 1] && !ft_strcmp(str[i + 1], "pa")))
			|| (!ft_strcmp(str[i], "pa") && (str[i + 1] && !ft_strcmp(str[i + 1], "pb"))))
			i += 2;
		else
			ft_printf("%s\n", str[i++]);
	}
	return (ft_free_args(str), 1);
}
