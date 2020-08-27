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
	if (parser->flag1 || parser->is_p)
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
	if (parser->flag2)
		ft_printerr();
	if (parser->flag1 == 0)
	{
		if (parser->width)
		{
			if (parser->precision)
			{
				if ((parser->precision > type->arg_len && parser->precision < parser->width) || parser->precision > parser->width)
					parser->precision = type->arg_len;
				ft_printsp(parser->width - parser->precision, type);
			}
			else
				ft_printsp(parser->width - type->arg_len, type);
		}
		else
		{
			if (parser->precision < type->arg_len)
				ft_printsp(parser->precision - type->arg_len, type);
		}
	}
	if (parser->is_p > 0 && parser->precision == 0)
		type->arg_len = 0;
	else if (!parser->precision)
		ft_putstr(type->arg_str, type->arg_len);	
	else
		ft_putstr(type->arg_str, parser->precision);
	if (parser->flag1)
	{
		if (parser->width)
		{
			if (parser->precision)
			{
				if ((parser->precision > type->arg_len && parser->precision < parser->width) || parser->precision > parser->width)
					parser->precision = type->arg_len;
				ft_printsp(parser->width - parser->precision, type);
			}
			else
				ft_printsp(parser->width - type->arg_len, type);
		}
		else
			ft_printsp(parser->precision - type->arg_len, type);
	}
}

void	ft_printpt(s_parser *parser, s_type *type)
{
	type->arg_int = (unsigned long)type->arg_pt;
	if (parser->flag1 == 0)
		ft_printsp(parser->width - type->arg_len, type);
	ft_putstr("0x", 2);
	ft_puthex(type->arg_int);
	if (parser->flag1)
		ft_printsp(parser->width - type->arg_len, type);
}

void	ft_printhex(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->precision)
		parser->flag2 = 0;
	if (parser->flag1 == 0)
	{
		if (parser->flag2)
			ft_print0(parser->width - type->arg_len, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
	}
	if (parser->precision > type->arg_len)
		ft_print0(parser->precision - type->arg_len, type);
	if (parser->is_p && parser->precision == 0 && type->arg_hex == 0)
		type->arg_len = 0;
	else
	{
	if (type->arg_char == 'x')
		ft_puthex(type->arg_hex);
	if (type->arg_char == 'X')
		ft_putheX(type->arg_hex);
	}
	if (parser->flag1)
		ft_printsp(parser->width - type->arg_len, type);
}
