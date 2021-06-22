NAME=fractol
CC=gcc
CFLAGS=-lbsd -lmlx -lX11 -lXext -lm
SRC=ft_utils.c ft_tab.c ft_frame.c ft_fract.c ft_fract1.c ft_arg.c main.c

OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
