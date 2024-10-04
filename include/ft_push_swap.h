/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:12:28 by madamou           #+#    #+#             */
/*   Updated: 2024/10/04 21:18:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_stacks;

int					ft_check_if_int(char *str);
int					ft_check_if_duplicate(char **str, int index);
int					ft_check_if_number(char **argv, int index, int i);
int					ft_len_stack(t_stack *st);
int					*ft_sort_tab(int *tab, int len_tab);
int					ft_find_pivot(t_stack *stack, int len_stack);
int					ft_less_movement(t_stack *stack_a, t_stack *stack_b,
						int len_stackb, int len_stacka);
int					ft_find_nb(t_stack *stack, int nb);
int					ft_find_nb_stacka(t_stack *stack_a, int nb);
int					ft_find_next(t_stack *stack, int nb);
int					ft_less(int a, int b);
int					ft_find_trois_quart(t_stack *stack, int len_stack);
int					ft_find_un_quart(t_stack *stack, int len_stack);
int					*ft_less_movement_in_b(int *test, int len_stackb);
int					ft_is_empty_stack(t_stack *st);
int					ft_check_if_sort(t_stack *stack_a, t_stack *stack_b);
int					ft_stock_movement(char *move, int cas, t_stacks *stacks);
int					ft_format_print(char *buffer);
int					ft_write(int fd, char *str, size_t len);

char				**ft_concatenate_all_args(char **argv);
char				**ft_free_args(char **argv);
char				**ft_check_args(char **argv);

t_stack				*ft_push_stack(t_stack *st, int nb);
t_stack				*ft_clear_stack(t_stack *st);
t_stack				*ft_args_to_stack(char **argv);
t_stack				*ft_swap_a(t_stacks *stacks);
t_stack				*ft_2_numbers(t_stacks *stacks);
t_stack				*ft_if_3_numbers(t_stacks *stacks);
t_stack				*ft_push_swap(t_stack *stack_a);
t_stack				*ft_swap_b(t_stacks *stacks);
t_stack				*ft_rotate_a(t_stacks *stacks, int cas);
t_stack				*ft_rotate_b(t_stacks *stacks, int cas);
t_stack				*ft_rev_rotate_a(t_stacks *stacks, int cas);
t_stack				*ft_rev_rotate_b(t_stacks *stacks, int cas);
t_stack				*ft_del_up_stack(t_stack *stack);

t_stacks			*ft_push_a(t_stacks *stacks);
t_stacks			*ft_push_b(t_stacks *stacks);
t_stacks			*ft_place_top_b(t_stacks *imad, int nb, int len_stackb);
t_stacks			*ft_presort_stack_a_part1(t_stacks *stacks, int pivot);
t_stacks			*ft_presort_stack_a_part2(t_stacks *stacks, int un_quart);

void				ft_pa_ra_or_rra(t_stacks *stacks, int len_stackb,
						int len_stacka);
#endif
