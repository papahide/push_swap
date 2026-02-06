# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 13:47:28 by paapahid          #+#    #+#              #
#    Updated: 2026/02/07 00:08:02 by paapahid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -g -Wall -Wextra -Werror

CC = cc

SRC = main.c \
	checkers.c \
	split.c \
	create_stack.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	tiny_sort.c \
	utils_array.c \
	utils_stack.c

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