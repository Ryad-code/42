
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	type
{
	int len_arg;
	int arg_int;
	char arg_char;
	char *arg_pchar;
}		s_type;

typedef struct	parser
{
	int cursor;
	int flag1;
	int flag2;
	int width;
	int precision;
}		s_parser;	

int	ft_printf(const char *s, ...);

void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putnbr(int nb);
void	ft_conv(char *tmp, s_parser *parser, s_type *type, va_list list);

int	ft_strlen(const char *s);
char    *ft_strdup(const char *s);

s_parser    ft_init_p(s_parser *parser);
s_type    ft_init_t(s_type *type);

int	fdcurs(const char *s);
int	ctcurs(const char *s);

void	ft_flags(char *s, s_parser *parser);
void	ft_width(char *s, s_parser *parser, va_list list);
void	ft_precision(char *s, s_parser *parser, va_list list);
void	ft_len_arg(s_type *type);

void	ft_print(const char *s);
void	ft_put_options(s_parser parser);
void	ft_f_print(s_parser *parser, s_type *type);
#endif
