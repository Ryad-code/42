#include "libftprintf.h"

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(long nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void    ft_print(const char *s, s_type *type)
{
	int i;

	i = 0;
	while (s[i] != '%' && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	type->f_len = type->f_len + i;
}

void	ft_print0(int nb, s_type *type)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		i++;
	}
	type->f_len = type->f_len + i;
}

void	ft_printsp(int nb, s_type *type)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
	type->f_len = type->f_len + i;
}
