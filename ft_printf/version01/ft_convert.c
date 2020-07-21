
#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_conv(char *tmp, s_parser *parser, s_type *type, va_list list)
{
	if (tmp[parser->cursor] == 'd' || tmp[parser->cursor] == 'i')
	{
		type->arg_int = va_arg(list, int);
		ft_len_arg(type);
		ft_printint(parser, type);
	}
	if (tmp[parser->cursor] == 'c')
	{
		type->arg_char = (char) va_arg(list, int);
		ft_len_arg(type);
		ft_printc(parser, type);
	}
	if (tmp[parser->cursor] == 's')
	{
		type->arg_str = (char *) va_arg(list, char *);
		ft_len_arg(type);
		ft_printstr(parser, type);
	}
}
