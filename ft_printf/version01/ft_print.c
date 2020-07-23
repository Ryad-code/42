
#include "ft_printf.h"

void    ft_print(const char *s, s_type *type)
{
                int i;

                i = 0;
                while (s[i] != '%' && s[i] != '\0')
                {
                        ft_putchar(s[i]);
                        i++;
                }
		type->f_len = type->f_len + i;
}

void	ft_print0(int nb, s_type *type)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		i++;
	}
	type->f_len = type->f_len + i;
}

void	ft_printsp(int nb, s_type *type)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
	type->f_len = type->f_len + i;
}

void	ft_printint(s_parser *parser, s_type *type)
{
	int res;

	res = 0;
	if (type->arg_int < 0)
		res++;
	if (parser->flag1 || parser->precision)
		parser->flag2 = 0;
	if (parser->flag2) 
	{
		if (type->arg_int < 0)
			ft_putchar('-');
		ft_print0(parser->width - type->len_arg, type);
	}
	if (parser->flag1 == 0 && parser->flag2 == 0)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision - res, type);
		else
			ft_printsp(parser->width - type->len_arg, type);
	}
	if (parser->precision)
	{
		if (type->arg_int < 0)
			ft_putchar('-');
		ft_print0(parser->precision - type->len_arg + res, type);
	}
	if (parser->precision == 0 && parser->flag2 == 0 && type->arg_int < 0)
		ft_putchar('-');
	ft_putnbr(type->arg_int);
	if (parser->flag1)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision - res, type);
		else
			ft_printsp(parser->width - type->len_arg, type);
	}	
}

void	ft_printc(s_parser *parser, s_type *type)
{
	if (parser->flag1 == 0)
		ft_printsp(parser->width - 1, type);
	ft_putchar(type->arg_char);
	if (parser->flag1)
		ft_printsp(parser->width - 1, type);
}

void    ft_printstr(s_parser *parser, s_type *type)
{
	int i;

	i = 0;
	if (parser->flag1 == 0)
	{
		if (parser->precision)
		{
			ft_printsp(parser->width - parser->precision, type);
			while (i < parser->precision)
			{
				ft_putchar(type->arg_str[i]);
				i++;
			}
		}
		else
		{
			ft_printsp(parser->width - type->len_arg, type);
			ft_putstr(type->arg_str);
		}
	}
	else
	{
		if (parser->precision)
		{
			while (i < parser->precision)
			{
				ft_putchar(type->arg_str[i]);
				i++;
			}
			ft_printsp(parser->width - parser->precision, type);
		}
		else
		{
			ft_putstr(type->arg_str);
			ft_printsp(parser->width - type->len_arg, type);
		}
	}
}

void	ft_printpt(s_parser *parser, s_type *type)
{
	type->arg_int = (unsigned long)type->arg_pt;
	if (parser->flag1 == 0)
		ft_printsp(parser->width - type->len_arg, type);
	ft_putstr("0x");
	ft_puthex(type->arg_int);
	if (parser->flag1)
		ft_printsp(parser->width - type->len_arg, type);
}

void	ft_printhex(s_parser *parser, s_type *type)
{
	if (parser->flag1 || parser->precision)
		parser->flag2 = 0;
	if (parser->flag1 == 0)
	{
		if (parser->flag2)
			ft_print0(parser->width - type->len_arg, type);
		else
			ft_printsp(parser->width - type->len_arg, type);
	}
	if (type->arg_char == 'x')
		ft_puthex(type->arg_hex);
	if (type->arg_char == 'X')
		ft_putheX(type->arg_hex);
	if (parser->flag1)
		ft_printsp(parser->width - type->len_arg, type);
}
