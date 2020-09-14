/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:15:12 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 15:24:57 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printu1(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->is_p)
		parser->flag2 = 0;
	if (parser->is_p && parser->precision && parser->precision < type->arg_len)
		parser->precision = type->arg_len;
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
		if (parser->is_p && parser->precision == 0 && type->arg_u == 0)
			(void)type->arg_u;
		else
			ft_putnbr(type->arg_u);
	}
	ft_printu2(parser, type);
}

void	ft_printu2(s_parser *parser, s_type *type)
{
	if (parser->flag1)
	{
		if (parser->precision)
		{
			ft_print0(parser->precision - type->arg_len, type);
			ft_putnbr(type->arg_u);
			ft_printsp(parser->width - parser->precision, type);
		}
		else
		{
			if (parser->is_p && parser->precision == 0 && type->arg_u == 0)
				(void)type->arg_u;
			else
				ft_putnbr(type->arg_u);
			ft_printsp(parser->width - type->arg_len, type);
		}
	}
}
