# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/15 13:37:43 by mlaouedj          #+#    #+#              #
#    Updated: 2021/11/16 18:06:12 by mlaouedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-pthread -Wall -Wextra -Werror -g3 -fsanitize=address
NAME=philo
SRC=ft_actions.c ft_init.c ft_routine.c ft_time.c ft_utils.c main.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
