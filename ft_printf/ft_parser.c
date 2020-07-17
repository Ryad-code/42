
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

void	ft_width(char *s, s_parser *parser)
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
		parser->s_width = 1;
	}
	parser->cursor = parser->cursor + i;
}

void	ft_precision(char *s, s_parser *parser)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		i++;
		res++;
	}
	parser->precision = res;
	if (s[i] == '*')
	{
		i++;
		parser->s_precision = 1;
	}
	parser->cursor = parser->cursor + i;
}

