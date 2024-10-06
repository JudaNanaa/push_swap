/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:06:02 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 01:25:39 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putendl(char const *s)
{
	if (write(1, s, ft_lenstr(s)) == -1)
		return;
	if (write(1, "\n", 1) == -1)
		return;
}

/*int main(void)
{
	ft_putendl("bonsoir le monde.");
}*/