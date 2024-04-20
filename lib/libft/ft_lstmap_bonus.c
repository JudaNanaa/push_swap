/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:00:58 by madamou           #+#    #+#             */
/*   Updated: 2024/03/25 23:51:04 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*buff;
	t_list	*result;
	t_list	*final;

	final = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		buff = f(lst->content);
		result = ft_lstnew(buff);
		if (!result)
		{
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, result);
		lst = lst->next;
	}
	return (final);
}

// Fonction pour changer la capitalisation des lettres
/*void *change_capitalization(void *str) {
	char *s = (char *)str;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32; // Convertir en majuscule
		}
	}
	return ((void *)s);
}

// Fonction pour afficher les éléments de la liste
void	print_list(t_list *lst) {
	while (lst) {
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

// Fonction pour supprimer le contenu d'un nœud
void	del_content(void *content) {
	free(content);
}

int	main(void) {
	// Création de la liste initiale
	t_list *lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(strdup("hello")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("openai")));

	printf("Liste initiale : ");
	print_list(lst);

	// Application de ft_lstmap avec la fonction de changement de capitalisation
	t_list *new_lst = ft_lstmap(lst, &change_capitalization, &del_content);

	printf("Nouvelle liste avec la capitalisation modifiée : ");
	print_list(new_lst);

	// Libération de la mémoire
	while (new_lst) {
		t_list *temp = new_lst;
		new_lst = new_lst->next;
		free(temp);
	}
	return (0);
}*/