
CC=gcc
AR=ar
CFLAGS=-g -Wall -Wextra -Werror
ARFLAGS=rc
NAME=libftprintf.a
SRC=ft_printf.c ft_utils.c ft_defparser.c ft_printint.c ft_printu.c ft_printhex.c ft_printpt.c ft_printchar.c ft_printper.c ft_print_utils1.c ft_print_utils2.c ft_print_utils3.c ft_deftype.c ft_arg_len1.c ft_arg_len2.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
