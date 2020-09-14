#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	type
{
	int arg;
	int f_len;
	int arg_len;
	long arg_int;
	unsigned int arg_u;
	long arg_hex;
	void *arg_pt;
	char arg_char;
	char *arg_str;
}			s_type;

typedef struct	parser
{
	int cursor;
	int flag1;
	int flag2;
	int width;
	int precision;
	int is_p;
}			s_parser;

int ft_printf(const char *s, ...);

void    ft_putchar(char c);
void    ft_putstr(const char *s, int n);
void    ft_putnbr(long nb);
void    ft_print(const char *s, s_type *type);
void    ft_print0(int nb, s_type *type);
void    ft_printsp(int nb, s_type *type);
void	ft_printerr();

void	ft_hex(s_type *type);
void	ft_defhex(char tab[16]);
void    ft_defhex2(char tab[16]);
void	ft_puthex(unsigned long nb);
void    ft_puthex2(unsigned long nb);

void	ft_printsign(int nb);
void	ft_printint1(s_parser *parser, s_type *type);
void    ft_printint2(s_parser *parser, s_type *type, int sign);
void    ft_printint3(s_parser *parser, s_type *type, int sign);
void	ft_printu1(s_parser *parser, s_type *type);
void    ft_printu2(s_parser *parser, s_type *type);


void    ft_printchar(s_parser *parser, s_type *type);
void    ft_printstr(s_parser *parser, s_type *type);
void    ft_printpt(s_parser *parser, s_type *type);
void    ft_printhex1(s_parser *parser, s_type *type);
void    ft_printhex2(s_parser *parser, s_type *type);
void    ft_printhex3(s_parser *parser, s_type *type);
void    ft_printper(s_parser *parser, s_type *type);

void	ft_flags(char *s, s_parser *parser);
void    ft_width(char *s, s_parser *parser, va_list list);
void    ft_precision(char *s, s_parser *parser, va_list list);

void    ft_init_t(s_type *type);
void    ft_init_p(s_parser *parser);

int ft_strlen(const char *s);
int fdcurs(const char *s);
int ctcurs(const char *s);
char *ft_strdup(const char *s);

void ft_deftype01(char *s, s_parser *parser, s_type *type, va_list list);
void ft_deftype02(char *s, s_parser *parser, s_type *type, va_list list);
void ft_deftype03(char *s, s_parser *parser, s_type *type, va_list list);
void ft_deftype04(char *s, s_parser *parser, s_type *type);

void ft_arg_len1(s_type *type);
void ft_arg_len2(s_type *type);
void ft_arg_len3(s_type *type);
void ft_arg_len4(s_type *type);
void ft_arg_len5(s_type *type);
void ft_arg_len6(s_parser *parser, s_type *type);

#endif
