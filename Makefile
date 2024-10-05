# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 21:03:54 by madamou           #+#    #+#              #
#    Updated: 2024/10/05 02:17:54 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = mandatory/

SRCS_BONUS_DIR = bonus_part/

OBJS_DIR = .objets/

SRCS = main.c check_args.c int_to_stack.c functions_stack.c 2numbers.c \
		stack_mouvement.c functions_stack2.c 3numbers.c \
		stack_mouvement2.c push_swap.c find_pivot.c less_movement.c \
		less_movement2.c stack_a_to_stack_b.c format_sortie.c

SRCS_BONUS = check_args_bonus.c checker_bonus.c int_to_stack_bonus.c \
		main_bonus.c stack_mouvement_bonus.c stack_mouvement2_bonus.c functions_stack_bonus.c \
		free_if_error_bonus.c

SRCS := $(SRCS:%=$(SRCS_DIR)/%)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

SRCS_BONUS := $(SRCS_BONUS:%=$(SRCS_BONUS_DIR)/%)

OBJS_BONUS = $(SRCS_BONUS:$(SRCS_BONUS_DIR)/%.c=$(OBJS_DIR)/%.o)

MAKEFLAGS   += --no-print-directory

DIR_DUP     = mkdir -p $(@D)

NAME = push_swap

NAME_BONUS = checker

LIBFT = libft.a

all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -I include -L ./libft -lft -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : all $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -I include -L ./libft -lft  -o $@

$(OBJS_DIR)/%.o: $(SRCS_BONUS_DIR)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus
