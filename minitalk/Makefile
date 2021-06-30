# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 12:39:46 by mlaouedj          #+#    #+#              #
#    Updated: 2021/06/30 12:53:10 by mlaouedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=server
NAME2=client
CFLAGS=-Wall -Wextra -Werror

all :
	gcc -Wall -Wextra -Werror server.c -o $(NAME1)
	gcc -Wall -Wextra -Werror client.c -o $(NAME2)

clean :
	rm client.o server.o

fclean : 
	rm $(NAME1) $(NAME2)

re : fclean all

