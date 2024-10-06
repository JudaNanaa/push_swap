/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:06:20 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 01:28:23 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	if (write(1, str, ft_strlen(str)) == -1)
		return;
}

/*int main(void)
{
	ft_putstr("je suis gentil");
	ft_putstr("\n");
}*/
