/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:34:21 by madamou           #+#    #+#             */
/*   Updated: 2024/06/10 00:01:47 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../include/libft.h"

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

int					ft_check_if_number(char **argv, int index, int i);
int					ft_check_if_int(char *str);
int					ft_check_if_duplicate(char **str, int index);
int					ft_len_stack(t_stack *st);
int					ft_is_empty_stack(t_stack *st);
int					ft_check_if_sort(t_stack *stack_a, t_stack *stack_b);

char				**ft_concatenate_all_args(char **argv);
char				**ft_check_args(char **argv);
char				**ft_free_args(char **argv);

t_stack				*ft_swap_a_bonus(t_stack *stack_a);
t_stack				*ft_swap_b_bonus(t_stack *stack_b);
t_stack				*ft_rotate_a_bonus(t_stack *stack_a);
t_stack				*ft_rotate_b_bonus(t_stack *stack_b);
t_stack				*ft_rev_rotate_a_bonus(t_stack *stack_a);
t_stack				*ft_rev_rotate_b_bonus(t_stack *stack_b);
t_stack				*ft_clear_stack(t_stack *st);
t_stack				*ft_push_stack(t_stack *st, int nb);

t_stacks			*ft_push_a_bonus(t_stacks *st);
t_stacks			*ft_args_to_stack(char **argv);
t_stacks			*ft_push_b_bonus(t_stacks *stacks);
t_stacks			*ft_execute_prompt(char *line, t_stacks *st);

void				ft_free_error(t_stacks *st);

#endif