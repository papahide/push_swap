# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 13:47:28 by paapahid          #+#    #+#              #
#    Updated: 2026/02/20 23:39:44 by paapahid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC = push_swap.c \
	checkers.c \
	split.c \
	create_stack.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	tiny_sort.c \
	big_sort.c \
	utils_array.c \
	utils_stack.c \
	utils_big_sort.c \
	utils_find.c \
	utils_set.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re