# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 21:03:54 by madamou           #+#    #+#              #
#    Updated: 2024/04/27 20:05:21 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c check_args.c int_to_stack.c functions_stack.c 2numbers.c \
		stack_a_and_b.c stack_mouvement.c functions_stack2.c 3numbers.c \
		stack_mouvement2.c 4-6numbers.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I include -L lib -lftprintf -lft -o $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus