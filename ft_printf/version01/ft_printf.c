
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int i;
	char *tmp;
	s_type type;
	s_parser parser;

	i = 0;
	tmp = ft_strdup(s);
//......................................................................................
	va_list list;
	va_start(list, s);
//......................................................................................	
	while (i < ctcurs(s))
	{
		ft_init_p(&parser);
		ft_init_t(&type);

		ft_print(tmp);

		parser.cursor = fdcurs(tmp) + 1;
		ft_flags(&tmp[parser.cursor], &parser);
		ft_width(&tmp[parser.cursor], &parser, list);
		ft_precision(&tmp[parser.cursor], &parser, list);
		ft_conv(tmp, &parser, &type, list);

		tmp = &tmp[parser.cursor + 1];
		i++;
//		printf("\nprecision = %d\n", parser.precision);
//		printf("width = %d\n", parser.width);
//		printf("flag1 = %d\n", parser.flag1);
//		printf("flag2 = %d\n", parser.flag2);
//		printf("len = %d\n\n", type.len_arg);
	}
	ft_print(tmp);
	tmp = NULL;
	free(tmp);
	return (0);		
}
