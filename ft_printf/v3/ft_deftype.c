#include "libftprintf.h"

void	ft_deftype(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'd' || s[parser->cursor] == 'i')
	{
		type->arg_int = va_arg(list, int);
		type-> arg = 1;
		if (parser->is_p && parser->precision == 0 && type->arg_int == 0)
			type->arg_len = 0;
		else
			ft_arg_len(parser, type);
		ft_printint(parser, type);
	}
	else if (s[parser->cursor] == 'u')
	{
		type->arg_u = va_arg(list, unsigned int);
		type-> arg = 2;
		if (parser->is_p && parser->precision == 0 && type->arg_u == 0)
			type->arg_len = 0;
		else
			ft_arg_len(parser, type);
		ft_printu(parser, type);
	}
	else if (s[parser->cursor] == 'x' || s[parser->cursor] == 'X')
	{
		type->arg_hex = (unsigned int)va_arg(list, unsigned int);
		type->arg = 3;
		type->arg_char = s[parser->cursor];
		if (type->arg_hex == 0 && parser->is_p && parser->precision == 0)
			type->arg_len = 0;
		else
			ft_arg_len(parser, type);
		ft_printhex(parser, type);
	}
	else if (s[parser->cursor] == 'p')
	{
		type->arg_pt = va_arg(list, void*);
		type->arg = 4;
		ft_arg_len(parser, type);
		type->arg_len += 2;
		ft_printpt(parser, type);
	}
	else if (s[parser->cursor] == 'c')
	{
		type->arg_char = (char)va_arg(list, int);
		type->arg = 5;
		ft_arg_len(parser, type);
		ft_printchar(parser, type);
	}
	else if (s[parser->cursor] == 's')
	{
		type->arg_str = va_arg(list, char*);
		type->arg = 6;
		if (type->arg_str == NULL)
			type->arg_str = "(null)";
		if (parser->is_p && parser->precision == 0)
			type->arg_len = 0;
		else
			ft_arg_len(parser, type);
		ft_printstr(parser, type);
	}
	else if (s[parser->cursor] == '%')
	{
		type->arg_len = 1;
		ft_printper(parser, type);
	}
}


