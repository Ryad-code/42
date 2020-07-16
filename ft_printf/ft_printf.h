
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
	int flag1;
	int flag2;
	int width;
	int c_width;
	int precision;
}		s_parser;	

int	ft_printf(const char *s, ...);

void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putnbr(int nb);

int	ft_strlen(const char *s);
void    ft_print(const char *s);
char    *ft_strdup(const char *s);

void    ft_init(s_parser parser);
void    ft_init1(s_type type);

int	fdcurs(const char *s);
int	ctcurs(const char *s);

void	ft_flags(char *s, s_parser *parser);
void	ft_width(char *s, s_parser *parser);
#endif
