/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:05:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 01:23:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return;
}

/*int main(void)
{
	char c = 'c';
	int fd;

	fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
	ft_putchar_fd(c, fd);
}*/