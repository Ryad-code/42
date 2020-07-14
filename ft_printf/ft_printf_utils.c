
#include "ft_printf.h"

void	ft_init(s_parser parser)
{
	parser.cursor = 0;
	parser.width = 0;
	parser.precision = 0;
	parser.lenght = 0;
}

void	ft_init1(s_type type)
{
	type.arg_int = 0;
	type.arg_char = '\0';
	type.arg_pchar = NULL;
}

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putstr(const char *s, int n)
{
	int i;

	i = 0;
	while (s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}					
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);									
		ft_putnbr(nb % 10);

	}
	else
	ft_putchar(nb + '0');
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
