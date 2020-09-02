#include "libftprintf.h"

void	ft_deftype(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'd' || s[parser->cursor] == 'i')
	{
		type->arg_int = va_arg(list, int);
		if (parser->is_p && parser->precision == 0)
			type->arg_len = 0;
		else
			ft_arg_len(type);
		ft_printint(parser, type);
	}
	else if (s[parser->cursor] == 'u')
	{
		type->arg_u = va_arg(list, unsigned int);
		ft_arg_len(type);
		ft_printu(parser, type);
	}
	else if (s[parser->cursor] == 'c')
	{
		type->arg_char = (char)va_arg(list, int);
		ft_arg_len(type);
		ft_printchar(parser, type);
	}
	else if (s[parser->cursor] == 's')
	{
		type->arg_str = (char *)va_arg(list, char *);
		if (type->arg_str == NULL)
			type->arg_str = "(null)";
		ft_arg_len(type);
		ft_printstr(parser, type);
	}
	else if (s[parser->cursor] == 'p')
	{
		type->arg_pt = (void *) va_arg(list, void *);
		type->arg_len = 12;
		ft_printhex(parser, type);
	}
	else if (s[parser->cursor] == 'x' || s[parser->cursor] == 'X')
	{
		type->arg_hex = (unsigned int) va_arg(list, unsigned int);
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


