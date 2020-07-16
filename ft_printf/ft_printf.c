
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int i;
	char *tmp;
	s_type type;
	s_parser parser;

	i = 0;
	tmp = NULL;
	ft_init(parser);
	ft_init1(type);
//........................................................................
	va_list list;
	va_start(list, s);
//........................................................................	

	tmp = ft_strdup(s);
	while (i < ctcurs(s))
	{
		ft_print(tmp);

		ft_flags(&tmp[fdcurs(tmp) + 1], &parser);
		ft_width(&tmp[fdcurs(tmp) + 1 + parser.flag1 + parser.flag2], &parser);
		
		ft_putflag2(parser);

		if (tmp[fdcurs(tmp) + 1 + parser.flag1 + parser.flag2 + parser.c_width] == 'c' || tmp[fdcurs(tmp) + 1] == 'i')
		{
			type.arg_char = (char) va_arg(list, int);
			ft_putchar(type.arg_char);
		}
		if (tmp[fdcurs(tmp) + 1 + parser.flag1 + parser.flag2 + parser.c_width] == 's')
		{
			type.arg_pchar = (char *) va_arg(list, char *);
			ft_putstr(type.arg_pchar);
		}
		if (tmp[fdcurs(tmp) + 1 + parser.flag1 + parser.flag2 + parser.c_width] == 'd')
		{
			type.arg_int = va_arg(list, int);
			ft_putnbr(type.arg_int);
		}
		i++;
		tmp = &tmp[fdcurs(tmp) + 2 + parser.flag1 + parser.flag2 + parser.c_width];
	}
	ft_print(tmp);
	tmp = NULL;
	free(tmp);
	return (0);
		
}
