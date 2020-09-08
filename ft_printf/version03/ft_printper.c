#include "libftprintf.h"

void	ft_printper(s_parser *parser, s_type *type)
{
    if (parser->flag1 == 0)
    {
		if (parser->flag2)
			ft_print0(parser->width - type->arg_len, type);
		else
        	ft_printsp(parser->width - type->arg_len, type);
        ft_putchar('%');
    }
    else if (parser->flag1)
    {
        ft_putchar('%');
        ft_printsp(parser->width - type->arg_len, type);
    }
}
