/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:44:04 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 15:52:31 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_defhex(char tab[16])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		tab[i] = i + 48;
		i++;
	}
	while (i < 16)
	{
		tab[i] = 'a' + j;
		i++;
		j++;
	}
}

void	ft_defhex2(char tab[16])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		tab[i] = i + 48;
		i++;
	}
	while (i < 16)
	{
		tab[i] = 'A' + j;
		i++;
		j++;
	}
}

void	ft_puthex(unsigned long nb)
{
	char tab_hex[16];

	ft_defhex(tab_hex);
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else
		ft_putchar(tab_hex[nb]);
}

void	ft_puthex2(unsigned long nb)
{
	char tab_hex[16];

	ft_defhex2(tab_hex);
	if (nb >= 16)
	{
		ft_puthex2(nb / 16);
		ft_puthex2(nb % 16);
	}
	else
		ft_putchar(tab_hex[nb]);
}

void	ft_hex(s_type *type)
{
	if (type->arg_char == 'x')
		ft_puthex(type->arg_char);
	if (type->arg_char == 'X')
		ft_puthex2(type->arg_char);
	(void)type->arg_char;
}
