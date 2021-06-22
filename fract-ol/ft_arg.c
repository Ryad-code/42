/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:40:38 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/22 12:34:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_check(char *a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(a);
	if (a[i] == '-')
		a++;
	if (ft_isdigit(a[i]) == 1)
		return (1);
	a++;
	if (a[i] != '.' && a[i] != '\0')
		return (2);
	a++;
	if (len > 2)
	{
		while (a[i] != '\0')
		{
			if (ft_isdigit(a[i]) == 1)
				return (3);
			i++;
		}
	}
	return (0);
}

double	ft_set_nb(char	*a)
{
	int		i;
	int		res_1;
	double	res_2;
	double	res;

	i = 0;
	res_1 = ft_atoi(a);
	a += 2;
	res_2 = ft_atoi(a);
	while (i < ft_strlen(a))
	{
		res_2 = res_2 / 10;
		i++;
	}
	res = res_1 + res_2;
	return (res);
}
