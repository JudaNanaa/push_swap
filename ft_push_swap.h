/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:12:28 by madamou           #+#    #+#             */
/*   Updated: 2024/04/25 20:47:19 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./include/ft_printf.h"
# include "./include/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef enum
{
	false,
	true
}	bool;

typedef enum
{
	stacka,
	stackb
}	stack;

int					ft_check_args(char **argv);
int					ft_check_if_int(char *str);
int					ft_check_if_duplicate(char **str, int index);
int					ft_check_if_number(char **argv, int index, int i);
int					ft_len_stack(t_stack *st);

bool				ft_is_empty_stack(t_stack *st);
bool ft_check_if_sort(t_stack **stack);

char				**ft_concatenate_all_args(char **argv);
char				**ft_free_args(char **argv);

t_stack				*ft_push_stack(t_stack *st, int nb);
t_stack				*ft_clear_stack(t_stack *st);
t_stack				*ft_args_to_stack(char **argv);
t_stack				*ft_swap_a(t_stack *stack_a);
t_stack				*ft_if_2_numbers(t_stack *stack_a);
t_stack				*ft_all_stacks(t_stack *stack_a);
t_stack				*ft_swap_b(t_stack *stack_b);

void				ft_print_stack(t_stack *st);
#endif