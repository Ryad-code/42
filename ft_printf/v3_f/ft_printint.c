/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:12:22 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 15:16:33 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printsign(int nb)
{
	if (nb > 0)
		ft_putchar('-');
}

void	ft_printint1(s_parser *parser, s_type *type)
{
	int sign;

	sign = 0;
	if (type->arg_int < 0)
		sign++;
	if (parser->flag1 || parser->is_p)
		parser->flag2 = 0;
	if (parser->precision && parser->precision < type->arg_len)
		parser->precision = 0;
	ft_printint2(parser, type, sign);
}

void	ft_printint2(s_parser *parser, s_type *type, int sign)
{
	if (parser->flag1 == 0)
	{
		if (parser->precision)
		{
			ft_printsp(parser->width - parser->precision - sign, type);
			ft_printsign(sign);
			ft_print0(parser->precision - type->arg_len + sign, type);
		}
		else if (parser->flag2)
		{
			ft_printsign(sign);
			ft_print0(parser->width - type->arg_len, type);
		}
		else
		{
			ft_printsp(parser->width - type->arg_len, type);
			ft_printsign(sign);
		}
		if (parser->is_p && parser->precision == 0 && type->arg_int == 0)
			(void)type->arg_int;
		else
			ft_putnbr(type->arg_int);
	}
	ft_printint3(parser, type, sign);
}

void	ft_printint3(s_parser *parser, s_type *type, int sign)
{
	if (parser->flag1)
	{
		if (parser->precision)
		{
			ft_printsign(sign);
			ft_print0(parser->precision - type->arg_len + sign, type);
			ft_putnbr(type->arg_int);
			ft_printsp(parser->width - parser->precision - sign, type);
		}
		else
		{
			ft_printsign(sign);
			if (parser->is_p && parser->precision == 0 && type->arg_int == 0)
				(void)type->arg_int;
			else
				ft_putnbr(type->arg_int);
			ft_printsp(parser->width - type->arg_len, type);
		}
	}
}
