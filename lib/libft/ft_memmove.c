/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:12:47 by madamou           #+#    #+#             */
/*   Updated: 2024/03/23 02:55:45 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_src;
	unsigned char	*n_dest;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	if (n_src < n_dest)
	{
		i = n + 1;
		while (--i > 0)
			n_dest[i - 1] = n_src[i - 1];
	}
	else
	{
		i = -1;
		while (++i < n)
			n_dest[i] = n_src[i];
	}
	return (dest);
}

/*int	main(void)
{
	char imad[300] = "bonjour";
	char src[] = "salut";
	printf("%s\n", (imad));
	printf("%p\n", memmove(imad, src, 5));
	printf("%s\n", (imad));
	printf("%s\n", (src));
	char imad1[300] = "bonjour";
	char src1[] = "salut";
	printf("%s\n", (imad1));
	printf("%p\n", ft_memmove(imad1, src1, 5));
	printf("%s\n", (imad1));
}*/