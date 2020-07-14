
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	type
{
	int arg_int;
	char arg_char;
	char *arg_pchar;
}		s_type;

typedef struct	parser
{
	int cursor;
	int width;
	int precision;
	int lenght;
}		s_parser;	

int	ft_printf(const char *s, ...);

void	ft_putchar(char c);
void	ft_putstr(const char *s, int n);
void	ft_putnbr(int nb);

int	ft_strlen(char *s);
void    ft_init(s_parser parser);
void    ft_init1(s_type type);
int	fdcurs(const char *s);
void	ft_type(char c, s_type type);

#endif
