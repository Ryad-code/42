#include "libftprintf.h"

void	ft_printint(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->precision)
		parser->flag2 =  0;
	if (parser->flag2)
		ft_print0(parser->width - type->arg_len, type);
	if (parser->flag1 == 0 && parser->flag2 == 0)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
	}
	if (parser->precision)
		ft_print0(parser->precision - type->arg_len, type);
	ft_putnbr(type->arg_int);
	if (parser->flag1)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
	}
}

void	ft_printchar(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->precision)
		parser->flag2 =  0;
	ft_putchar(type->arg_char);
}

void    ft_printstr(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->precision)
	parser->flag2 =  0;
	ft_putstr(type->arg_str);
}
