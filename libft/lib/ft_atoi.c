/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/08 19:52:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int i;
	int j;
	int sign;
	int nb;

	i = 0;
	j = 1;
	sign = 1;
	nb = 0;
	while (str[i] == 't' || str[i] == 'v' || str[i] == 'n' ||
	str[i] == 'r' || str[i] == 'f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i = i - 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + ((str[i] - 48) * j);
		j = j * 10;
		i--;
	}
	return (nb * sign);
}
