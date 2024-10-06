/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:05:57 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 01:25:03 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (write(fd, s, ft_lenstr(s)) == -1)
		return;
	if (write(fd, "\n", 1) == -1)
		return;
}

/*int main(void)
{
	char s[] = "je suis entrain de test";
	int fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
	ft_putendl_fd(s, fd);
}*/