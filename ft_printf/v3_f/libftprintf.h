/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:40:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:47:11 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_type
{
	int				arg;
	int				f_len;
	int				arg_len;
	long			arg_int;
	unsigned int	arg_u;
	long			arg_hex;
	void			*arg_pt;
	char			arg_char;
	char			*arg_str;
}					t_type;

typedef	struct		s_parser
{
	int	cursor;
	int flag1;
	int flag2;
	int width;
	int precision;
	int	is_p;
}					t_parser;

int					ft_printf(const char *s, ...);

void				ft_putchar(char c);
void				ft_putstr(const char *s, int n);
void				ft_putnbr(long nb);
void				ft_print(const char *s, t_type *type);
void				ft_print0(int nb, t_type *type);
void				ft_printsp(int nb, t_type *type);
void				ft_printerr();

void				ft_hex(t_type *type);
void				ft_defhex(char tab[16]);
void				ft_defhex2(char tab[16]);
void				ft_puthex(unsigned long nb);
void				ft_puthex2(unsigned long nb);

void				ft_printsign(int nb);
void				ft_printint1(t_parser *parser, t_type *type);
void				ft_printint2(t_parser *parser, t_type *type, int sign);
void				ft_printint3(t_parser *parser, t_type *type, int sign);
void				ft_printu1(t_parser *parser, t_type *type);
void				ft_printu2(t_parser *parser, t_type *type);

void				ft_printchar(t_parser *parser, t_type *type);
void				ft_printstr1(t_parser *parser, t_type *type);
void				ft_printstr2(t_parser *parser, t_type *type);
void				ft_printpt(t_parser *parser, t_type *type);
void				ft_printhex1(t_parser *parser, t_type *type);
void				ft_printhex2(t_parser *parser, t_type *type);
void				ft_printhex3(t_parser *parser, t_type *type);
void				ft_printper(t_parser *parser, t_type *type);

void				ft_flags(char *s, t_parser *parser);
void				ft_width(char *s, t_parser *parser, va_list list);
void				ft_precision1(char *s, t_parser *parser, va_list list);
void				ft_precision2(char *s, t_parser *parser, int i, int res);

void				ft_init_t(t_type *type);
void				ft_init_p(t_parser *parser);

int					ft_strlen(const char *s);
int					fdcurs(const char *s);
int					ctcurs(const char *s);
char				*ft_strdup(const char *s);

void				ft_deftype01(char *s, t_parser *parser, t_type *type,
		va_list list);
void				ft_deftype02(char *s, t_parser *parser, t_type *type,
		va_list list);
void				ft_deftype03(char *s, t_parser *parser, t_type *type,
		va_list list);
void				ft_deftype04(char *s, t_parser *parser, t_type *type);

void				ft_arg_len1(t_type *type);
void				ft_arg_len2(t_type *type);
void				ft_arg_len3(t_type *type);
void				ft_arg_len4(t_type *type);
void				ft_arg_len5(t_type *type);
void				ft_arg_len6(t_parser *parser, t_type *type);

#endif
