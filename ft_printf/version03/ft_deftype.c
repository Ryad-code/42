#include "libftprintf.h"

void	ft_deftype(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'd' || s[parser->cursor] == 'i')
	{
		type->arg_int = va_arg(list, int);
		type-> arg = 1;
		if (parser->is_p && parser->precision == 0)
			type->arg_len = 0;
		else
			ft_arg_len(type);
		ft_printint(parser, type);
	}
	else if (s[parser->cursor] == 'u')
	{
		type->arg_u = va_arg(list, unsigned int);
		type-> arg = 2;
		ft_arg_len(type);
		ft_printu(parser, type);
	}
	else if (s[parser->cursor] == 'x' || s[parser->cursor] == 'X')
	{
		type->arg_hex = (unsigned int) va_arg(list, unsigned int);
		type->arg = 3;
		if (type->arg_hex == 0)
			type->arg_len = 1;
		else
			ft_arg_len(type);
		type->arg_char = s[parser->cursor];
		ft_printhex(parser, type);
	}
	else if (s[parser->cursor] == '%')
		ft_putchar('%');
}


