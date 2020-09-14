/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deftype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:56:33 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 13:19:18 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_deftype01(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'd' || s[parser->cursor] == 'i')
	{
		type->arg_int = va_arg(list, int);
		type->arg = 1;
		if (parser->is_p && parser->precision == 0 && type->arg_int == 0)
			type->arg_len = 0;
		else
			ft_arg_len1(type);
		ft_printint(parser, type);
	}
	else if (s[parser->cursor] == 'u')
	{
		type->arg_u = va_arg(list, unsigned int);
		type->arg = 2;
		if (parser->is_p && parser->precision == 0 && type->arg_u == 0)
			type->arg_len = 0;
		else
			ft_arg_len2(type);
		ft_printu(parser, type);
	}
	ft_deftype02(s, parser, type, list);
}

void	ft_deftype02(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'x' || s[parser->cursor] == 'X')
	{
		type->arg_hex = (unsigned int)va_arg(list, unsigned int);
		type->arg = 3;
		type->arg_char = s[parser->cursor];
		if (type->arg_hex == 0 && parser->is_p && parser->precision == 0)
			type->arg_len = 0;
		else
			ft_arg_len3(type);
		ft_printhex(parser, type);
	}
	else if (s[parser->cursor] == 'p')
	{
		type->arg_pt = va_arg(list, void*);
		type->arg = 4;
		ft_arg_len4(type);
		type->arg_len += 2;
		ft_printpt(parser, type);
	}
	ft_deftype03(s, parser, type, list);
}

void	ft_deftype03(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'c')
	{
		type->arg_char = (char)va_arg(list, int);
		type->arg = 5;
		ft_arg_len5(type);
		ft_printchar(parser, type);
	}
	else if (s[parser->cursor] == 's')
	{
		type->arg_str = va_arg(list, char*);
		type->arg = 6;
		if (type->arg_str == NULL)
			type->arg_str = "(null)";
		if (parser->is_p && parser->precision == 0)
			type->arg_len = 0;
		else
			ft_arg_len6(parser, type);
		ft_printstr(parser, type);
	}
	ft_deftype04(s, parser, type);
}

void	ft_deftype04(char *s, s_parser *parser, s_type *type)
{
	if (s[parser->cursor] == '%')
	{
		type->arg_len = 1;
		ft_printper(parser, type);
	}
}
