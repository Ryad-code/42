
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	s_type type;
	s_parser parser;
	ft_init(parser);
	ft_init1(type);
//........................................................................
	va_list list;
	va_start(list, s);
//........................................................................	
	ft_putstr(s, fdcurs(s));

	if (s[fdcurs(s) + 1] == 'c' || s[fdcurs(s) + 1] == 'i')
	{
		type.arg_char = (char) va_arg(list, int);
		ft_putchar(type.arg_char);
	}
	if (s[fdcurs(s) + 1] == 's')
	{
		type.arg_pchar = (char *) va_arg(list, char *);
		ft_putstr(type.arg_pchar, ft_strlen(type.arg_pchar));
	}
	if (s[fdcurs(s) + 1] == 'd')
	{
		type.arg_int = va_arg(list, int);
		ft_putnbr(type.arg_int);
	}

	ft_putstr(&s[fdcurs(s) + 2], 10);
	return (0);
		
}
