# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 05:56:03 by mlaouedj          #+#    #+#              #
#    Updated: 2021/08/03 02:30:49 by mlaouedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
FLAGS=-Wall -Wextra -Werror
SRC= ft_arg_01.c ft_arg_02.c ft_basic_op.c ft_create.c ft_get_min.c ft_insert_sort_01.c ft_insert_sort_02.c ft_insert_sort_03.c ft_insert_sort_04.c ft_operation_01.c ft_operation_02.c ft_operation_03.c ft_order.c ft_sort_01.c ft_sort_02.c main.c

all:
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

