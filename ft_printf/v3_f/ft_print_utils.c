#include "libftprintf.h"

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

void	ft_printerr()
{
	ft_putstr("Options result in undefined behavior", 36);
}
