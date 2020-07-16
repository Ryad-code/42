
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int i;
	char *tmp;
	s_type type;
	s_parser parser;

	i = 0;
	tmp = NULL;
//........................................................................
	va_list list;
	va_start(list, s);
//........................................................................	

	tmp = ft_strdup(s);
	while (i < ctcurs(s))
	{
		ft_init(parser);
		ft_init1(type);
		
		ft_print(tmp);

		parser.cursor = fdcurs(tmp) + 1;
		ft_flags(&tmp[parser.cursor], &parser);
		ft_width(&tmp[parser.cursor], &parser);
	
//		if (parser.s_width == 1)
//		{
//			parser.width = va_arg(list, int);
//		}
//		printf("%d\n", parser.width);
		ft_putflags(parser);

//..........................................................................................		
		if (tmp[parser.cursor] == 'c')
		{
			type.arg_char = (char) va_arg(list, int);
			ft_putchar(type.arg_char);
		}
		if (tmp[parser.cursor] == 's')
		{
			type.arg_pchar = (char *) va_arg(list, char *);
			ft_putstr(type.arg_pchar);
		}
		if (tmp[parser.cursor] == 'd' || tmp[parser.cursor] == 'i')
		{
			type.arg_int = va_arg(list, int);
			ft_putnbr(type.arg_int);
		}
//..........................................................................................
		i++;
		tmp = &tmp[parser.cursor + 2];
	}
	ft_print(tmp);
	tmp = NULL;
	free(tmp);
	return (0);
		
}
