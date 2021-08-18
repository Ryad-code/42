# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 14:22:13 by mlaouedj          #+#    #+#              #
#    Updated: 2021/08/18 14:24:54 by mlaouedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=gcc
FLAGS=-Werror -Wall -Wextra
SRC=ft_actions.c ft_init.c ft_routine.c ft_time.c ft_utils.c main.c

all:
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
