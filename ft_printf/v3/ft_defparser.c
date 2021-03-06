
#include "libftprintf.h"

void	ft_flags(char *s, s_parser *parser)
{
	int i;
	int res1;
	int res2;

	i = 0;
	res1 = 0;
	res2 = 0;
	while (s[i] == '-' || s[i] == '0')
	{
		if (s[i] == '-')
			res1++;
		else if (s[i] == '0')
			res2++;
		i++;
	}
	parser->flag1 = res1;
	parser->flag2 = res2;
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
	if (s[i] == '*')
	{
		i++;
		parser->width = va_arg(list, int);
		if (parser->width < 0)
		{
			parser->width = -parser->width;
			parser->flag1 = 1;
		}
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
	if (i > 0)
		parser->is_p = 1;
	if (parser->precision < 0)
	{
		parser->precision = 0;
			parser->is_p = 0;
	}
	parser->cursor = parser->cursor + i;
}

void	ft_arg_len(s_parser *parser, s_type *type)
{
	int i;
	long nb;
	unsigned long nbu;

	i = 0;
	nb = 0;
	nbu = 0;
	if (type->arg == 1)
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
	else if (type->arg == 2)
	{
		nbu = type->arg_u;
		while (nbu >= 10)
		{
			nbu = nbu / 10;
			i++;
		}
		type->arg_len = i + 1;
	}
	else if (type->arg == 3)
	{
		nb = type->arg_hex;
		while (nb >= 16)
		{
			nb = nb / 16;
			i++;
		}
		type->arg_len = i + 1;
	}
	else if (type->arg == 4)
	{
		nbu = (unsigned long)type->arg_pt;
		while (nbu >= 16)
		{
			nbu = nbu / 16;
			i++;
		}
		type->arg_len = i + 1;
	}
	else if (type->arg == 5)
		type->arg_len = 1;
	else if (type->arg == 6)
	{
		if (parser->is_p && parser->precision < ft_strlen(type->arg_str))
			type->arg_len = parser->precision;
		else
			type->arg_len = ft_strlen(type->arg_str);
	}
}
