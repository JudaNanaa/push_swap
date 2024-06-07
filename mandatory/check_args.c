/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:16:54 by madamou           #+#    #+#             */
/*   Updated: 2024/06/04 14:14:53 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

char	**ft_concatenate_all_args(char **argv)
{
	int		index;
	char	*strcat_args;

	index = 2;
	strcat_args = ft_calloc(sizeof(char), (ft_strlen(argv[1]) + 1 + 1));
	if (!strcat_args)
		exit(EXIT_FAILURE);
	strcat_args = ft_strcat(strcat_args, argv[1]);
	while (argv[index])
	{
		strcat_args = ft_realloc(strcat_args, (ft_strlen(argv[index]) + 1));
		if (!strcat_args)
			exit(EXIT_FAILURE);
		strcat_args = ft_strcat(strcat_args, " ");
		strcat_args = ft_strcat(strcat_args, argv[index++]);
	}
	argv = ft_split(strcat_args, " ");
	return (free(strcat_args), argv);
}

int	ft_check_if_number(char **argv, int index, int i)
{
	if ((argv[index][i] < '0' || argv[index][i] > '9') && (argv[index][i] != '-'
			&& argv[index][i] != '+'))
		return (0);
	if (argv[index][i] == '-' || argv[index][i] == '+')
	{
		if (argv[index][i + 1] < '0' || argv[index][i + 1] > '9' || i != 0)
			return (0);
	}
	return (1);
}

char	**ft_check_args(char **argv)
{
	int	index;
	int	i;

	index = 0;
	argv = ft_concatenate_all_args(argv);
	if (!argv)
		exit(EXIT_FAILURE);
	while (argv[index])
	{
		i = 0;
		while (argv[index][i])
		{
			if (!ft_check_if_number(argv, index, i))
				return (argv = ft_free_args(argv), NULL);
			i++;
		}
		if (!ft_check_if_int(argv[index]) || !ft_check_if_duplicate(argv,
				index))
			return (ft_free_args(argv), NULL);
		index++;
	}
	return (argv);
}

int	ft_check_if_int(char *str)
{
	int				index;
	int				sign;
	long long int	result;

	index = 0;
	result = 0;
	sign = 1;
	if (ft_strlen(str) >= 12)
		return (0);
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
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_strcmp(str[i], str[index]) == 0)
			return (0);
		if (ft_atoi(str[i]) == ft_atoi(str[index]))
			return (0);
		i++;
	}
	return (1);
}
