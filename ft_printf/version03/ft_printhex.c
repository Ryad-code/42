#include "libftprintf.h"

void	ft_printhex(s_parser *parser, s_type *type)
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
                if (parser->is_p && parser->precision == 0 && type->arg_hex == 0)
                        (void)type->arg_hex;
		else
		{
			if (type->arg_char == 'x')
				ft_puthex(type->arg_hex);
			else if (type->arg_char == 'X')
				ft_putheX(type->arg_hex);
			(void)type->arg_char;
		}
	}
	else if (parser->flag1)
	{
		if (parser->precision)
                {
                        ft_print0(parser->precision - type->arg_len, type);
                        if (type->arg_char == 'x')
				ft_puthex(type->arg_hex);
			else if (type->arg_char == 'X')
				ft_putheX(type->arg_hex);
			(void)type->arg_char;
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
					ft_putheX(type->arg_hex);
				(void)type->arg_char;
			}
                        ft_printsp(parser->width - type->arg_len, type);
                }
	}
}

void	ft_printpt(s_parser *parser, s_type *type)
{
	
	if (type->arg_pt == NULL)
	{
		type->arg_str = "(nil)";
		ft_printstr(parser, type);
	}
	else
	{
		type->arg_hex = (unsigned long)type->arg_pt;
		if (parser->flag1 == 0)
			ft_printsp(parser->width - type->arg_len, type);
		ft_putstr("0x", 2);
		ft_puthex(type->arg_hex);
		if (parser->flag1)
			ft_printsp(parser->width - type->arg_len, type);
	}
}
