/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:12:28 by madamou           #+#    #+#             */
/*   Updated: 2024/05/02 21:29:33 by madamou          ###   ########.fr       */
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

typedef enum bool
{
	false,
	true
}					t_bool;

typedef enum stacks
{
	stacka,
	stackb
}					t_stacks;

int					ft_check_args(char **argv);
int					ft_check_if_int(char *str);
int					ft_check_if_duplicate(char **str, int index);
int					ft_check_if_number(char **argv, int index, int i);
int					ft_len_stack(t_stack *st);
int	ft_find_biggest_nb(t_stack *stack_a, int pivot);
int *ft_sort_tab(int *tab, int len_tab);
int ft_find_pivot(t_stack *stack);
int ft_max(t_stack *stack_a);
int ft_min(t_stack *stack_a);


t_bool				ft_is_empty_stack(t_stack *st);
t_bool				ft_check_if_sort(t_stack *stack_a, t_stack *stack_b);

char				**ft_concatenate_all_args(char **argv);
char				**ft_free_args(char **argv);

t_stack				*ft_pa_ra_or_rra(t_stack *stack_a, t_stack *stack_b, int cas);
t_stack				*ft_push_stack(t_stack *st, int nb);
t_stack				*ft_clear_stack(t_stack *st);
t_stack				*ft_args_to_stack(char **argv);
t_stack				*ft_swap_a(t_stack *stack_a);
t_stack				*ft_if_2_numbers(t_stack *stack_a);
t_stack				*ft_if_3_numbers(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_push_swap(t_stack *stack_a);
t_stack				*ft_swap_b(t_stack *stack_b);
t_stack				*ft_rotate_a(t_stack *stack_a, int cas);
t_stack				*ft_rotate_b(t_stack *stack_b);
t_stack				*ft_rev_rotate_a(t_stack *stack_a, int cas);
t_stack				*ft_rev_rotate_b(t_stack *stack_b);
t_stack				*ft_push_a(t_stack *stack_a, t_stack *stack_b, int cas);
t_stack				*ft_push_b(t_stack *stack_a, t_stack *stack_b, int cas);
t_stack				*ft_before_other_numbers(t_stack *stack_a, t_stack *stack_b);
t_stack				*ft_del_up_stack(t_stack *stack);

#endif