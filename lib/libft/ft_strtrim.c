/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:07:11 by marvin            #+#    #+#             */
/*   Updated: 2024/03/30 23:53:49 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_charset(char c, char const *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_lenstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_malloc_size(char const *s1, char const *sep)
{
	int	i;
	int	j;
	int	len_s;

	len_s = ft_lenstr(s1);
	i = 0;
	j = 0;
	while (ft_is_in_charset(s1[i], sep) == 1)
		i++;
	while (ft_is_in_charset(s1[len_s - 1 - j], sep) == 1)
		j++;
	return (len_s - (i + j));
}

static void	ft_fill_str(char const *s1, char *str, char const *sep)
{
	int	i;
	int	j;
	int	k;
	int	len_s;

	len_s = ft_lenstr(s1);
	k = 0;
	i = 0;
	j = 0;
	while (ft_is_in_charset(s1[i], sep) == 1)
		i++;
	while (ft_is_in_charset(s1[len_s - 1 - j], sep) == 1)
		j++;
	while (i < len_s - j)
		str[k++] = s1[i++];
	str[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *sep)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_malloc_size(s1, sep) + 1));
	if (str == NULL)
		return (NULL);
	ft_fill_str(s1, str, sep);
	return (str);
}

/*int main(void)
{
	char    str[] = "salut la compagnie salfut";
	char    set[] = "asult";
	char *imad = ft_strtrim(str, set);
	printf("%s\n", imad);
	free(imad);
	return (0);
}*/