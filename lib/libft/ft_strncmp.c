/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:28:22 by madamou           #+#    #+#             */
/*   Updated: 2024/03/30 19:30:16 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*true_s1;
	unsigned char	*true_s2;

	true_s1 = (unsigned char *)s1;
	true_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (true_s1[i] != true_s2[i])
		{
			if (true_s1[i] < true_s2[i])
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char s1[] = "Bon";
	char s2[] = "Bon6";
	printf("%d\n", strncmp(s1, s2, 3));
	printf("%d\n", ft_strncmp(s1, s2, 3));
}*/