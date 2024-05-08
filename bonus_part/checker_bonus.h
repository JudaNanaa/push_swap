/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:34:21 by madamou           #+#    #+#             */
/*   Updated: 2024/05/08 23:29:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include "../include/libft.h"

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

int	ft_check_if_number(char **argv, int index, int i);
int	ft_check_if_int(char *str);
int	ft_check_if_duplicate(char **str, int index);

char	**ft_concatenate_all_args(char **argv);
char	**ft_check_args(char **argv);
char	**ft_free_args(char **argv);

t_stack	*ft_args_to_stack(char **argv);
t_stack	*ft_swap_a(t_stack *stack_a);
t_stack	*ft_swap_b(t_stack *stack_b);
t_stack	*ft_rotate_a(t_stack *stack_a, int cas);
t_stack	*ft_rotate_b(t_stack *stack_b, int cas);
t_stack	*ft_rev_rotate_a(t_stack *stack_a, int cas);
t_stack	*ft_rev_rotate_b(t_stack *stack_b, int cas);
t_stack	*ft_push_a(t_stack *stack_a, t_stack *stack_b, int cas);

t_stacks	*ft_push_b(t_stacks *stacks);


#endif