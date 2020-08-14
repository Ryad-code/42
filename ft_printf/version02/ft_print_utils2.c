#include "libftprintf.h"

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
