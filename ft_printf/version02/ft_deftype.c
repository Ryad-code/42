#include "libftprintf.h"

void	ft_deftype(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'd')
	{
		type->arg_int = va_arg(list, int);
		ft_putnbr(type->arg_int);
	}	
	if (s[parser->cursor] == 'c')
	{
		type->arg_char = (char)va_arg(list, int);
		ft_putchar(type->arg_char);
	}

	if (s[parser->cursor] == 's')
	{
		type->arg_str = va_arg(list, char*);
		ft_putstr(type->arg_str);
	}
}


