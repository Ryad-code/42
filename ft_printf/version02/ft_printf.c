#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	s_type type;
	s_parser parser;
	char *tmp;

	ft_init_t(&type);
	ft_init_p(&parser);
	tmp = ft_strdup(s);
	type.f_len = 0;

	va_list list;
	va_start(list, s);

	ft_print(tmp, &type);
	parser.cursor = fdcurs(s) + 1;

	ft_deftype(tmp, &parser, &type, list);

	tmp = &tmp[parser.cursor + 1];

	ft_print(tmp, &type);

	printf("%d\n", parser.cursor);
	return (type.f_len);
}
