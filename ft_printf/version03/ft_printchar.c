#include "libftprintf.h"

void	ft_printchar(s_parser *parser, s_type *type)
{
	if (parser->flag1 == 0)
	{
		ft_printsp(parser->width - type->arg_len, type);
		ft_putchar(type->arg_char);
	}
	else if (parser->flag1)
	{
		ft_putchar(type->arg_char);
		ft_printsp(parser->width - type->arg_len, type);
	}
}

void	ft_printstr(s_parser *parser, s_type *type)
{
	(void)parser;
	(void)type;
}
