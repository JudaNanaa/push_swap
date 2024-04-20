/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:30:23 by madamou           #+#    #+#             */
/*   Updated: 2024/03/25 14:57:51 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buff;

	buff = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = new;
		new->next = NULL;
	}
}

/*static t_list	*ft_lstnew1(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	main(void)
{
	// Création de quelques éléments de liste
	t_list *lst = NULL;
	t_list *elem1 = ft_lstnew1("Elem1");
	t_list *elem2 = ft_lstnew1("Elem2");
	t_list *elem3 = ft_lstnew1("Elem3");

	// Ajout des éléments à la fin de la liste
	ft_lstadd_back(&lst, elem1);
	ft_lstadd_back(&lst, elem2);
	ft_lstadd_back(&lst, elem3);

	// Affichage de la liste
	printf("Liste après l'ajout des éléments :\n");
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}*/