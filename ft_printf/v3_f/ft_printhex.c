/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:36:53 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 16:49:10 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printhex1(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->is_p)
		parser->flag2 = 0;
	if (parser->is_p && parser->precision && parser->precision < type->arg_len)
		parser->precision = type->arg_len;
	ft_printhex2(parser, type);
}

void	ft_printhex2(s_parser *parser, s_type *type)
{
	if (parser->flag1 == 0)
	{
		if (parser->precision)
		{
			ft_printsp(parser->width - parser->precision, type);
			ft_print0(parser->precision - type->arg_len, type);
		}
		else if (parser->flag2)
			ft_print0(parser->width - type->arg_len, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
		if (parser->is_p && parser->precision == 0 && type->arg_hex == 0)
			(void)type->arg_hex;
		else
			ft_hex(type);
	}
	ft_printhex3(parser, type);
}

void	ft_printhex3(s_parser *parser, s_type *type)
{
	if (parser->flag1)
	{
		if (parser->precision)
		{
			ft_print0(parser->precision - type->arg_len, type);
			ft_hex(type);
			ft_printsp(parser->width - parser->precision, type);
		}
		else
		{
			if (parser->is_p && parser->precision == 0 && type->arg_hex == 0)
				(void)type->arg_hex;
			else
			{
				if (type->arg_char == 'x')
					ft_puthex(type->arg_hex);
				else if (type->arg_char == 'X')
					ft_puthex2(type->arg_hex);
				(void)type->arg_char;
			}
			ft_printsp(parser->width - type->arg_len, type);
		}
	}
}
