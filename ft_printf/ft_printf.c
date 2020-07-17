
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int i;
	char *tmp;
	s_type type;
	s_parser parser;

	i = 0;
	tmp = NULL;
//......................................................................................
	va_list list;
	va_start(list, s);
//......................................................................................	

	tmp = ft_strdup(s);
	while (i < ctcurs(s))
	{
		ft_init_p(&parser);
		ft_init_t(&type);
		
		ft_print(tmp);

		parser.cursor = fdcurs(tmp) + 1;
		ft_flags(&tmp[parser.cursor], &parser);
		ft_width(&tmp[parser.cursor], &parser);
		ft_precision(&tmp[parser.cursor], &parser);
//........................................................................................		
		if (parser.s_width == 1)
			parser.width = va_arg(list, int);
//.........................................................................................
		if (parser.s_precision == 1)
			parser.precision = va_arg(list, int);
//.........................................................................................
//		ft_put_options(parser);
//.........................................................................................		
		if (tmp[parser.cursor] == 'c')
		{
			type.arg_char = (char) va_arg(list, int);
			ft_f_print(&parser, &type);	
		}
		if (tmp[parser.cursor] == 's')
		{
			type.arg_pchar = (char *) va_arg(list, char *);
			ft_f_print(&parser, &type);
		}
		if (tmp[parser.cursor] == 'd' || tmp[parser.cursor] == 'i')
		{
			type.arg_int = va_arg(list, int);
			ft_f_print(&parser, &type);
		}
		printf("\n%d\n", parser.cursor);
		printf("%d\n", parser.precision);
		printf("%d\n", parser.s_precision);
//..........................................................................................
		i++;
		tmp = &tmp[parser.cursor + 1];
	}
	ft_print(tmp);
	tmp = NULL;
	free(tmp);
	return (0);
		
}
