/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_len1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:25:57 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:41:10 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_arg_len1(t_type *type)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
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
}

void	ft_arg_len2(t_type *type)
{
	int				i;
	unsigned long	nbu;

	i = 0;
	nbu = 0;
	if (type->arg == 2)
	{
		nbu = type->arg_u;
		while (nbu >= 10)
		{
			nbu = nbu / 10;
			i++;
		}
		type->arg_len = i + 1;
	}
}

void	ft_arg_len3(t_type *type)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (type->arg == 3)
	{
		nb = type->arg_hex;
		while (nb >= 16)
		{
			nb = nb / 16;
			i++;
		}
		type->arg_len = i + 1;
	}
}
