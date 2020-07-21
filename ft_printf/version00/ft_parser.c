
#include "ft_printf.h"

void	ft_flags(char *s, s_parser *parser)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i] == '-')
	{
		i++;
		res++;
	}
	parser->flag1 = res;
	res = 0;
	while(s[i] == '0')
	{
		i++;
		res++;
	}
	parser->flag2 = res;
	parser->cursor = parser->cursor + i;
}

void	ft_width(char *s, s_parser *parser, va_list list)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (s[i] >= '0' && s[i] <= '9')
	{
		res = s[i] - '0';
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	parser->width = res;
	if (s[i] == '*' && s[i + 1] != '.')
	{
		i++;
		parser->width = va_arg(list, int);
	}
	parser->cursor = parser->cursor + i;
}

void	ft_precision(char *s, s_parser *parser, va_list list)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (s[i] == '*')
	{
		i++;
		parser->precision = va_arg(list, int);
	}
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	parser->precision = res;
	parser->cursor = parser->cursor + i;
}

void	ft_len_arg(s_type *type)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	if (type->arg_int)
	{
		nb = type->arg_int;
		while (nb > 10)
		{
			nb = nb / 10;
			i++;
		}
		type->len_arg = i + 1;
	}
	i = 0;
	if (type->arg_char)
		type->len_arg = 1;
	if (type->arg_pchar)
		type->len_arg = ft_strlen(type->arg_pchar);
}
