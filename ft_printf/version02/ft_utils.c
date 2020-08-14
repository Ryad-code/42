
#include "libftprintf.h"

void	ft_init_p(s_parser *parser)
{
	parser->cursor = 0;
	parser->flag1 = 0;
	parser->flag2 = 0;
	parser->width = 0;
	parser->precision = 0;
	parser->is_p = 0;
}

void	ft_init_t(s_type *type)
{
	type->arg_len = 0;
	type->arg_int = 0;
	type->arg_char = '\0';
	type->arg_str = NULL;
	type->arg_pt = NULL;
	type->arg_hex = 0;
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	fdcurs(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			return (i);
		i++;
	}
	return (0);
}

int	ctcurs(const char *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i - 1])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			res++;
		i++;
	}
	return (res);
}


char	*ft_strdup(const char *s)
{
	int i;
	char *dst;

	i = 0;
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (dst);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
