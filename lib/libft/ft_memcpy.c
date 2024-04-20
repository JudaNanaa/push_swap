/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:49:32 by madamou           #+#    #+#             */
/*   Updated: 2024/03/23 02:48:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_src;
	unsigned char	*n_dest;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	i = -1;
	while (++i < n)
		n_dest[i] = n_src[i];
	return (dest);
}

/*int	main(void)
{
	char imad[300] = "bonjour";
	char src[] = "salut";
	printf("%s\n", (imad));
	printf("%p\n", memcpy(imad, src, 6));
	printf("%s\n", (imad));
	char imad1[300] = "bonjour";
	char src1[] = "salut";
	printf("%s\n", (imad1));
	printf("%p\n", ft_memcpy(imad1, src1, 6));
	printf("%s\n", (imad1));
}*/