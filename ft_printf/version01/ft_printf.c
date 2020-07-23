
#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int i;
	char *tmp;
	s_type type;
	s_parser parser;

	i = 0;
	tmp = ft_strdup(s);
	type.f_len = 0;
//......................................................................................
	va_list list;
	va_start(list, s);
//......................................................................................	
	while (i < ctcurs(s))
	{
		ft_init_p(&parser);
		ft_init_t(&type);

		ft_print(tmp, &type);

		parser.cursor = fdcurs(tmp) + 1;
		
		ft_flags(&tmp[parser.cursor], &parser);
		ft_width(&tmp[parser.cursor], &parser, list);
		ft_precision(&tmp[parser.cursor], &parser, list);
		
		ft_conv(tmp, &parser, &type, list);

		tmp = &tmp[parser.cursor + 1];
		type.f_len = type.f_len + type.len_arg;
		i++;
//		printf("\nwidth = %d\n", parser.width);
//		printf("\nprecision = %d\n", parser.precision);
//		printf("\nlen = %d\n", type.len_arg);
//		printf("\nfin = %d\n", type.f_len);
//		printf("\npt = %p\n", type.arg_pt);
//		printf("\nhex = %ld\n", type.arg_hex);
	}
	ft_print(tmp, &type);
	tmp = NULL;
	free(tmp);
	return (type.f_len);		
}
