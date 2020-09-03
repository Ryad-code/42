#include "libftprintf.h"

void	ft_printhex(s_parser *parser, s_type *type)
{
	(void)parser;
	ft_puthex(type->arg_hex);
}
