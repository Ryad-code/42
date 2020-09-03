#include "libftprintf.h"

void	ft_printsign(int nb)
{
	if (nb > 0)
		ft_putchar('-');
}

void	ft_printint(s_parser *parser, s_type *type)
{
	int sign;

	sign = 0;
	if (type->arg_int < 0)
		sign++;
	if (parser->flag1 || parser->is_p)
		parser->flag2 = 0;
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
	else if (parser->flag1)
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

void	ft_printu(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->is_p)
		parser->flag2 = 0;
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
	else if (parser->flag1)
	{
		if (parser->precision)
                {
                        ft_print0(parser->precision - type->arg_len, type);
                        ft_putnbr(type->arg_u);
                        ft_printsp(parser->width - parser->precision, type);
                }
                else
                {
                        if (parser->is_p && parser->precision == 0 && type->arg_int == 0)
                                (void)type->arg_u;
                        else
                                ft_putnbr(type->arg_u);
                        ft_printsp(parser->width - type->arg_len, type);
                }
	}
}

