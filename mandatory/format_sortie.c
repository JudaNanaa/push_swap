/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_sortie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:44:43 by madamou           #+#    #+#             */
/*   Updated: 2024/08/28 21:35:04 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	ft_stock_movement(char *move, int cas, t_stacks *stacks)
{
	static char	*buffer;

	if (cas == 1)
	{
		buffer = ft_realloc(buffer, ft_strlen(move) + 1);
		if (!buffer)
			return (-1);
		buffer = ft_strcat(buffer, move);
	}
	if (cas == 2)
	{
		if (ft_format_print(buffer) == -1)
		{
			free(buffer);
			buffer = NULL;
			(ft_clear_stack(stacks->stack_a), ft_clear_stack(stacks->stack_b));
			free(stacks);
			exit(EXIT_FAILURE);
		}
		free(buffer);
		buffer = NULL;
	}
	return (0);
}

void	ft_print_movements_rr(char **split, char *comp, char *srch, int i)
{
	int	j;

	j = i + 1;
	if (ft_strcmp(split[i], comp) == 0)
	{
		while (split[j])
		{
			if (ft_strcmp(split[j], srch) == 0)
			{
				ft_write(STDOUT_FILENO, "rr\n", 3);
				ft_strcpy(split[j], "");
				break ;
			}
			j++;
		}
		if (!split[j] && split[i][0])
		{
			ft_write(STDOUT_FILENO, split[i], ft_strlen(split[i]));
			ft_write(STDOUT_FILENO, "\n", 1);
		}
	}
}

void	ft_print_movements_rrr(char **split, char *comp, char *srch, int i)
{
	int	j;

	j = i + 1;
	if (ft_strcmp(split[i], comp) == 0)
	{
		while (split[j])
		{
			if (ft_strcmp(split[j], srch) == 0)
			{
				ft_write(STDOUT_FILENO, "rrr\n", 4);
				ft_strcpy(split[j], "");
				break ;
			}
			j++;
		}
		if (!split[j] && split[i][0])
		{
			ft_write(STDOUT_FILENO, split[i], ft_strlen(split[i]));
			ft_write(STDOUT_FILENO, "\n", 1);
		}
	}
}

int	ft_format_print(char *buffer)
{
	char	**split_buffer;
	int		i;

	i = 0;
	split_buffer = ft_split(buffer, "\n");
	if (!split_buffer)
		return (-1);
	while (split_buffer[i])
	{
		ft_print_movements_rr(split_buffer, "ra", "rb", i);
		ft_print_movements_rr(split_buffer, "rb", "ra", i);
		ft_print_movements_rrr(split_buffer, "rra", "rrb", i);
		ft_print_movements_rrr(split_buffer, "rrb", "rra", i);
		i++;
	}
	ft_free_args(split_buffer);
	return (0);
}
