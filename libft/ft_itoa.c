/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 12:06:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/16 13:24:10 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlen(int n)
{
	int i;

	i = 0;
	if (n  == 0)
		i = 1;
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

char	*ft_revtab(char *s)
{
	int i;
	int j;
	char dst[ft_strlen(s)];

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < (ft_strlen(s) / 2))
	{
		dst[i] = s[i];
		s[i] = s[j - i];
		s[j - i] = dst[i];
		i++;

	}
	return (s);
}
char	*ft_itoa(int n)
{
	int i;
	int sign;
	char *dst;

	i = 0;
	sign = 1;
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * ft_getlen(n) + 1)))
		return (dst);
//	if (n == 0)
//	{
//		dst = "0\0";
//		return (dst);
//	}
//	if (n == -2147483648)
//	{
//		dst = "-2147483648\0";
//		return(dst);
//	}
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	while (n > 0)
	{
		dst[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (sign == -1)
	{
		dst[i] = '-';
		dst[i + 1] = '\0';
	}
	else
		dst[i] = '\0';
	return (ft_revtab(dst));
}
