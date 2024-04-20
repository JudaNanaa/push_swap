/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:17:41 by madamou           #+#    #+#             */
/*   Updated: 2024/03/23 01:33:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lensrc(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

static size_t	ft_min(size_t size, size_t result)
{
	if (size <= result)
		return (size);
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	while (dst[i])
		i++;
	result = i;
	if (size <= ft_lensrc(src))
	{
		if (ft_min(size, result) == size)
			return (size + ft_lensrc(src));
		return (result + ft_lensrc(src));
	}
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_lensrc(src) + result);
}

/*int main(void)
{
	char dest[300] = "oui";
	char src[] = "Salut";
	printf("%ld\n", strlcat(dest, src, 0));
	printf("%s\n", dest);
	char dest1[300] = "oui";
	char src1[] = "Salut";
	printf("%ld\n", ft_strlcat(dest1, src1, 0));
	printf("%s\n", dest1);
}*/