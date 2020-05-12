/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:40:46 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/12 17:48:18 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlen(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dst;

	i = ft_getlen(n);
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * i + 1)))
		return (dst);
	dst[i + 1] = '\0';
	if (n == 0)
	{
		dst[0] = 48;
		return (dst);
	}
	if (n < 0)
	{
		n = -n;
		dst[0] = '-';
	}
	while (n > 0)
	{
		dst[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (dst);
}
