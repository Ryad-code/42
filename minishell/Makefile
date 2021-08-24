# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 18:13:16 by mlaouedj          #+#    #+#              #
#    Updated: 2021/08/24 18:44:58 by mlaouedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
CC=gcc
FLAGS=-g3 -fsanitize=address -Werror -Wextra -Wall
SRC=ft_built_in.c ft_display.c ft_init.c ft_list.c ft_parser_01.c ft_env.c ft_router.c gnl/get_next_line.c gnl/get_next_line_utils.c main.c

all:
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
