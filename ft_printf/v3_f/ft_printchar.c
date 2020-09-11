#include "libftprintf.h"

void	ft_printchar(s_parser *parser, s_type *type)
{
	if (parser->flag1 == 0)
	{
		ft_printsp(parser->width - type->arg_len, type);
		ft_putchar(type->arg_char);
	}
	else if (parser->flag1)
	{
		ft_putchar(type->arg_char);
		ft_printsp(parser->width - type->arg_len, type);
	}
}

void	ft_printstr(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->is_p)
		parser->flag2 = 0;
	if (parser->flag1 == 0)
	{
		if (parser->is_p)
		{
			if (type->arg_str == NULL)
				parser->precision = 0;
			if (parser->precision > type->arg_len)
				parser->precision = type->arg_len;
			ft_printsp(parser->width - parser->precision, type);
			ft_putstr(type->arg_str, parser->precision);
		}
		else
		{
			ft_printsp(parser->width - type->arg_len, type);
			ft_putstr(type->arg_str, ft_strlen(type->arg_str));
		}
	}
	else if (parser->flag1)
	{
		if (parser->is_p)
		{
			if (type->arg_str == NULL)
				parser->precision = 0;
			if (parser->precision > type->arg_len)
				parser->precision = type->arg_len;
			ft_putstr(type->arg_str, parser->precision);
			ft_printsp(parser->width - parser->precision, type);
		}
		else
		{
			ft_putstr(type->arg_str, ft_strlen(type->arg_str));
			ft_printsp(parser->width - type->arg_len, type);
		}
	}
}
