
#include "ft_printf.h"

void	ft_init(s_parser parser)
{
	parser.cursor = 0;
	parser.flag1 = 0;
	parser.flag2 = 0;
	parser.width = 0;
	parser.s_width = 0;
	parser.precision = 0;
	parser.s_precision = 0;
}

void	ft_init1(s_type type)
{
	type.arg_int = 0;
	type.arg_char = '\0';
	type.arg_pchar = NULL;
}

void    ft_print(const char *s)
{
	        int i;

		i = 0;
		while (s[i] != '%' && s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
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
	while (s[i])
	{
		if (s[i] == '%')
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
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
