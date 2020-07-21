
#include "ft_printf.h"

void    ft_print(const char *s)
{
                int i;

                i = 0;
                while (s[i] != '%' && s[i] != '\0')
                {
                        ft_putchar(s[i]);
                        i++;
                }
}

void	ft_print0(int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		i++;
	}
}

void	ft_printsp(int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
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
		ft_print0(parser->width - type->len_arg);
	}
	if (parser->flag1 == 0 && parser->flag2 == 0)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision - res);
		else
			ft_printsp(parser->width - type->len_arg);
	}
	if (parser->precision)
	{
		if (type->arg_int < 0)
			ft_putchar('-');
		ft_print0(parser->precision - type->len_arg + res);
	}
	if (parser->precision == 0 && parser->flag2 == 0 && type->arg_int < 0)
		ft_putchar('-');
	ft_putnbr(type->arg_int);
	if (parser->flag1)
	{
		if (parser->precision)
			ft_printsp(parser->width - parser->precision - res);
		else
			ft_printsp(parser->width - type->len_arg);
	}	
}




void	ft_printc(s_parser *parser, s_type *type)
{
}

void    ft_printstr(s_parser *parser, s_type *type)
{

}
