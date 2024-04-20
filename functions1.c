/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:16:54 by madamou           #+#    #+#             */
/*   Updated: 2024/04/21 00:15:28 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_args(char **argv)
{
	int	index;
	int	i;

	index = 1;
	while (argv[index])
	{
		i = 0;
		while (argv[index][i])
		{
			if ((argv[index][i] < '0' || argv[index][i] > '9')
				&& (argv[index][i] != '-' && argv[index][i] != '+'))
				return (0);
			if (argv[index][i] == '-' || argv[index][i] == '+')
			{
				if (argv[index][i + 1] < '0' || argv[index][i + 1] > '9')
					return (0);
			}
			i++;
		}
		if (!ft_check_if_int(argv[index])
			|| !ft_check_if_duplicate(argv, index))
			return (0);
		index++;
	}
	return (1);
}

int	ft_check_if_int(char *str)
{
	int				index;
	int				sign;
	long long int	result;

	index = 0;
	result = 0;
	sign = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		index++;
		if (str[0] == '-')
			sign = -sign;
	}
	while (str[index] >= '0' && str[index] <= '9')
		result = (result * 10) + (str[index++] - '0');
	if ((result * sign) >= -2147483648 && (result * sign) <= 2147483647)
		return (1);
	return (0);
}

int	ft_check_if_duplicate(char **str, int index)
{
	int i;

	i = 1;
	while (i < index)
	{
		if (ft_strcmp(str[i++],str[index]) == 0)
			return (0);
	}
	return (1);
}
