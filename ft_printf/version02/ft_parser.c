
#include "libftprintf.h"

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
	if (s[i] == '*' && s[i + 1] == '.')
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
	if (s[i] == '.')
		i++;
	if (s[i] == '*')
	{
		i++;
		parser->precision = va_arg(list, int);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	if (parser->precision == 0)
		parser->precision = res;
	if (i == 0 && res == 0)
		parser->precision = -1;
	parser->cursor = parser->cursor + i;
}

void	ft_arg_len(s_type *type)
{
	int i;
	long nb;

	i = 0;
	nb = 0;
	if (type->arg_int)
	{
		nb = type->arg_int;
		if (type->arg_int < 0)
		{
			nb = -type->arg_int;
			i++;
		}
		while (nb >= 10)
		{
			nb = nb / 10;
			i++;
		}
		type->arg_len = i + 1;
	}
	if (type->arg_char)
		type->arg_len = 1;
	if (type->arg_str)
		type->arg_len = ft_strlen(type->arg_str);
	i = 0;
	if (type->arg_hex)
	{
		nb = type->arg_hex;
		while (nb >= 16)
		{
			nb = nb / 16;
			i++;
		}
		type->arg_len = i + 1;	
	}
}
