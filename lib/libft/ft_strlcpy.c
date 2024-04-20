/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:53:14 by madamou           #+#    #+#             */
/*   Updated: 2024/03/30 19:58:00 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenstr(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_lenstr(src));
}

/*int main(void)
{
	char dest[] = "";
	char src[] = "salut";
	printf("%ld\n", strlcpy(dest, src, 2));
	printf("%s\n", dest);
	char dest1[] = "";
	char src1[] = "salut";
	printf("%ld\n", strlcpy(dest1, src1, 2));
	printf("%s\n", dest1);
}*/