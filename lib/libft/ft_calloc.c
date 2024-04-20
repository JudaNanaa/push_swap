/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:42:25 by madamou           #+#    #+#             */
/*   Updated: 2024/03/28 14:57:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
		ptr[i++] = '\0';
	return ((void *)ptr);
}

/*int main(void)
{
	char *result;
	int i = 0;

	result = calloc(10, 0);
	if (result == NULL)
	{
		printf("NULL\n");
		free(result);
	}
	else
		while (i < 10)
		{
			if (result[i] == '\0')
				printf("c'est bon %d\n", i);
			i++;
		}
	i = 0;
	result = ft_calloc(10, 0);
	if (result == NULL)
	{
		printf("NULL\n");
		free(result);
	}
	else
		while (i < 10)
		{
			if (result[i] == '\0')
				printf("c'est bon %d\n", i);
			i++;
		}
}*/