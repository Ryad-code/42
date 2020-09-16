/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:25:01 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:42:14 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flags(char *s, t_parser *parser)
{
	int i;
	int res1;
	int res2;

	i = 0;
	res1 = 0;
	res2 = 0;
	while (s[i] == '-' || s[i] == '0')
	{
		if (s[i] == '-')
			res1++;
		else if (s[i] == '0')
			res2++;
		i++;
	}
	parser->flag1 = res1;
	parser->flag2 = res2;
	parser->cursor = parser->cursor + i;
}

void	ft_width(char *s, t_parser *parser, va_list list)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	parser->width = res;
	if (s[i] == '*')
	{
		i++;
		parser->width = va_arg(list, int);
		if (parser->width < 0)
		{
			parser->width = -parser->width;
			parser->flag1 = 1;
		}
	}
	parser->cursor = parser->cursor + i;
}

void	ft_precision1(char *s, t_parser *parser, va_list list)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (s[i] == '.')
		i++;
	if (s[i] == '*')
	{
		i++;
		parser->precision = va_arg(list, int);
	}
	ft_precision2(s, parser, i, res);
}

void	ft_precision2(char *s, t_parser *parser, int i, int res)
{
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	if (parser->precision == 0)
		parser->precision = res;
	if (i > 0)
		parser->is_p = 1;
	if (parser->precision < 0)
	{
		parser->precision = 0;
		parser->is_p = 0;
	}
	parser->cursor = parser->cursor + i;
}
