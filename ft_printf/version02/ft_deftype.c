#include "libftprintf.h"

void	ft_deftype(char *s, s_parser *parser, s_type *type, va_list list)
{
	if (s[parser->cursor] == 'd' || s[parser->cursor] == 'i' || s[parser->cursor] == 'u')
	{
		type->arg_int = va_arg(list, int);
		if (type->arg_int == 0)
			type->arg_len = 1;
		else
			ft_arg_len(type);
		ft_printint(parser, type);
	}	
	if (s[parser->cursor] == 'c')
	{
		type->arg_char = (char)va_arg(list, int);
		ft_arg_len(type);
		ft_printchar(parser, type);
	}

	if (s[parser->cursor] == 's')
	{
		type->arg_str = (char *)va_arg(list, char *);
		ft_arg_len(type);
		ft_printstr(parser, type);
	}
}


