/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:54:55 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/20 14:23:33 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlen(long *n, long *sign)
{
	int		i;
	long	nb;

	i = 0;
	nb = *n;
	if (*n == 0)
		i = 1;
	if (*n < 0)
	{
		i++;
		*n = nb * -1;
		*sign = -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_revtab(char *s)
{
	int		i;
	int		j;
	char	dst[ft_strlen(s)];

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

char 	*ft_prepmem(char *dst, long *n, long *sign)
{
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * ft_getlen(n, sign) + 1)))
		return (dst);
	return (dst);
}

char	*ft_itoa(int n)
{
	long	i[3];
	char	*dst;

	i[0] = 0;
	i[1] = 1;
	i[2] = n;
	dst = NULL;
	dst = ft_prepmem(dst, &i[2], &i[1]);
	if (i[2] == 0)
	{
		dst[0] = '0';
		return (dst);
	}
	while (i[2] > 0)
	{
		dst[i[0]] = (i[2] % 10) + 48;
		i[2] = i[2] / 10;
		i[0]++;
	}
	if (i[1] == -1)
	{
		dst[i[0]] = '-';
		i[0]++;
	}
	dst[i[0]] = '\0';
	return (ft_revtab(dst));
}
