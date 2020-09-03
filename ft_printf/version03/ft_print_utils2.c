#include "libftprintf.h"

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

void	ft_puthex(unsigned long nb)
{
	char tab_hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else
		ft_putchar(tab_hex[nb]);
}

void    ft_putheX(unsigned long nb)
{
	char tab_hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (nb >= 16)
	{
		ft_putheX(nb / 16);
		ft_putheX(nb % 16);
	}
	else
		ft_putchar(tab_hex[nb]);
}
