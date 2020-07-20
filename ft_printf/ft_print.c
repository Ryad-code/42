
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

void	ft_f_print(s_parser *parser, s_type *type)
{
	int i;

	i = 0;
	ft_len_arg(type);

	if ((parser->flag1) || (parser->precision))
		parser->flag2 = 0;
	else if (parser->flag2)
		while (i < (parser->width - type->len_arg))
		{
			if (parser->flag2)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	i = 0;
	while (i < (parser->precision - type->len_arg))
	{
		if (parser->flag2)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	if (type->arg_int)
		ft_putnbr(type->arg_int);
	if (type->arg_char)
		ft_putchar(type->arg_char);
	if (type->arg_pchar)
		ft_putstr(type->arg_pchar);
	i = 0;
	if (parser->flag1)
	{
		while (i < (parser->width - type->len_arg))
		{
				ft_putchar(' ');
				i++;
		}
	}
}
