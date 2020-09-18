/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:33:11 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/18 15:42:26 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print(const char *s, t_type *type)
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

void	ft_print0(int nb, t_type *type)
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

void	ft_printsp(int nb, t_type *type)
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
