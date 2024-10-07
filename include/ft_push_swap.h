/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:12:28 by madamou           #+#    #+#             */
/*   Updated: 2024/10/07 00:21:49 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_int
{
	int a;
	int b;
}t_int;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	t_int			len;
	struct s_stack	*first_a;
	struct s_stack	*last_a;
	struct s_stack	*first_b;
	struct s_stack	*last_b;
	t_int			index;
	int				mediane;
}					t_stacks;

int					ft_check_if_int(char *str);
int					ft_check_if_duplicate(char **str, int index);
int					ft_check_if_number(char **argv, int index, int i);
int					ft_len_stack(t_stack *st);
int					*ft_sort_tab(int *tab, int len_tab);
int					ft_less_movement(t_stacks *stacks);
int					ft_find_nb(t_stack *stack, int nb);
int					ft_find_nb_stacka(t_stack *stack_a, int nb);
int					ft_find_next(t_stack *stack, int nb);
int					ft_min(int a, int b);
int					ft_find_trois_quart(t_stack *stack, int len_stack);
int					ft_find_un_quart(t_stack *stack, int len_stack);
int					ft_is_empty_stack(t_stack *st);
int					ft_check_if_sort(t_stack *stack_a, t_stack *stack_b);
int					ft_stock_movement(char *move, int cas, t_stacks *stacks);
int					ft_format_print(char *buffer);
int					ft_write(int fd, char *str, size_t len);
int					ft_max(int a, int b);

char				**ft_concatenate_all_args(char **argv);
char				**ft_free_args(char **argv);
char				**ft_check_args(char **argv, int *index);

t_stack				*ft_push_stack(t_stack *st, int nb);
t_stack				*ft_clear_stack(t_stack *st);
t_stack				*ft_args_to_stack(char **argv, int len);
t_stack				*ft_push_swap(t_stack *stack_a);
t_stack				*ft_del_up_stack(t_stack *stack);

t_stacks			*ft_place_top_b(t_stacks *imad, int nb, int len_stackb);
t_stacks			*ft_presort_stack_a_part1(t_stacks *stacks, int pivot);
t_stacks			*ft_presort_stack_a_part2(t_stacks *stacks, int un_quart);

void				ft_find_pivot(t_stack *stack, int len_stack, int *pivot);
void				ft_rev_rotate_a(t_stacks *stacks, int cas);
void				ft_rev_rotate_b(t_stacks *stacks, int cas);
void				ft_push_a(t_stacks *stacks);
void				ft_push_b(t_stacks *stacks);
void				ft_swap_a(t_stacks *stacks);
void				ft_swap_b(t_stacks *stacks);
void				ft_rotate_a(t_stacks *stacks, int cas);
void				ft_rotate_b(t_stacks *stacks, int cas);
void				ft_if_3_numbers(t_stacks *stacks);
void				ft_2_numbers(t_stacks *stacks);
void				ft_less_movement_in_b(int *test, int len_stackb);
void				ft_pa_ra_or_rra(t_stacks *stacks);
void				ft_db_rotate(t_stacks *stacks);
void				ft_db_rev_rotate(t_stacks *stacks);

#endif
