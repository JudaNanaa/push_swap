/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:06:15 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 01:27:21 by madamou          ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd)
{
	if (write(fd, s, ft_lenstr(s)) == -1)
		return;
}

/*int main(void)
{
	char s[] = "je suis entrain de test";
	int fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0640);
	ft_putstr_fd(s, fd);
}*/