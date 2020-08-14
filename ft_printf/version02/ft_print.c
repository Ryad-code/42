#include "libftprintf.h"

void	ft_printint(s_parser *parser, s_type *type)
{
	int sign;
	int p;

	sign = 0;
	p = 0;
	if (parser->precision == 0 && type->arg_int == 0)
	{
		type->arg_len = 0;
		p = 1;
	}
	if (type->arg_int < 0)
		sign++;
	if (parser->flag1 || parser->precision)
		parser->flag2 =  0;
	if (parser->flag2)
	{
		if (sign == 1)
			ft_putchar('-');
		ft_print0(parser->width - type->arg_len, type);
	}
	if (parser->flag1 == 0 && parser->flag2 == 0)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision - sign, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
	}
	if (parser->precision)
	{
		if (sign == 1)
			ft_putchar('-');
		ft_print0(parser->precision - type->arg_len + sign, type);
	}
	if (parser->precision == 0 && parser->flag2 == 0 && type->arg_int < 0)
		ft_putchar('-');
	if (p == 0)
		ft_putnbr(type->arg_int);
	if (parser->flag1)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision - sign, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
	}
}

void	ft_printchar(s_parser *parser, s_type *type)
{
	if (parser->flag1 == 0)
		ft_printsp(parser->width - 1, type);
	ft_putchar(type->arg_char);
	if (parser->flag1)
		ft_printsp(parser->width - 1, type);
}

void    ft_printstr(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->precision)
	parser->flag2 =  0;
	ft_putstr(type->arg_str);
}
