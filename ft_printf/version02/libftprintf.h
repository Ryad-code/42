#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	type
{
	int f_len;
	int arg_len;
	long arg_int;
	long arg_hex;
	char arg_char;
	char *arg_str;
	void *arg_pt;
}			s_type;

typedef struct	parser
{
	int cursor;
	int flag1;
	int flag2;
	int width;
	int precision;
}			s_parser;

int ft_printf(const char *s, ...);

void    ft_putchar(char c);
void    ft_putstr(const char *s);
void    ft_putnbr(long nb);

void    ft_print(const char *s, s_type *type);
void    ft_print0(int nb, s_type *type);
void    ft_printsp(int nb, s_type *type);

void    ft_init_t(s_type *type);
void    ft_init_p(s_parser *parser);

int ft_strlen(const char *s);
int fdcurs(const char *s);
int ctcurs(const char *s);
char *ft_strdup(const char *s);

void ft_deftype(char *s, s_parser *parser, s_type *type, va_list list);
#endif
