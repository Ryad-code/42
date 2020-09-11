#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int i;
	char *tmp;

	s_type type;
	s_parser parser;
	va_list list;
	va_start(list, s);

	i = 0;
	tmp = ft_strdup(s);
	type.f_len = 0;
	while (i < ctcurs(s))
	{
		ft_init_t(&type);
		ft_init_p(&parser);

		ft_print(tmp, &type);
		parser.cursor = fdcurs(tmp) + 1;

		ft_flags(&tmp[parser.cursor], &parser);
		ft_width(&tmp[parser.cursor], &parser, list);
		ft_precision(&tmp[parser.cursor], &parser, list);

		ft_deftype(tmp, &parser, &type, list);
		type.f_len += type.arg_len;
 
		tmp = &tmp[parser.cursor + 1];
		i++;
//		printf("curs = %d\n", parser.cursor);
//		printf("f1 = %d\n", parser.flag1);
//		printf("f2 = %d\n", parser.flag2);
//		printf("w1 = %d\n", parser.width);
//		printf("p1 = %d\n", parser.precision);
//		printf("isp1 = %d\n", parser.is_p);
//		printf("ct = %d\n", ctcurs(s));
//		printf("len = %d\n", type.arg_len);
//		printf("f_len = %d\n", type.f_len);
//		printf("int = %ld\n", type.arg_int);
//		printf("u = %u\n", type.arg_u);
//		printf("hex = %lx\n", type.arg_hex);
//		printf("char = %c\n", type.arg_char);
//		printf("str = %s\n", type.arg_str);
//		printf("pt = %p\n", type.arg_pt);
	}
	ft_print(tmp, &type);
	tmp = NULL;
	free(tmp);
	return (type.f_len);
}
