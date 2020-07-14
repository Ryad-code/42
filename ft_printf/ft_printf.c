
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	sp_conv conv;
	ft_init(conv);

	va_list list;
	va_start(list, s);
	
	conv.cursor = fdcurs(s);
	ft_type(s[conv.cursor + 1], &conv);

	conv.arg = (int) va_arg(list, int);

	ft_putstr(s, conv.cursor);
	ft_putnbr(conv.arg);

	return (0);
		
}
