
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

void	ft_putflags(s_parser parser)
{
	int i;

	i = 0;
	while (i < parser.width)
	{
		if (parser.flag2 != 0 && parser.flag1 == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}	
}
