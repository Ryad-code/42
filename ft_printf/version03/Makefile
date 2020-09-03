
CC=gcc
AR=ar
CFLAGS=-g -Wall -Wextra -Werror
ARFLAGS=rc
NAME=libftprintf.a
SRC=ft_printf.c ft_utils.c ft_defparser.c ft_printint.c ft_printhex.c ft_printstr.c ft_print_utils.c ft_print_utils2.c ft_deftype.c

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
