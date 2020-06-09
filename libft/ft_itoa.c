/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:54:55 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/09 14:45:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	char				*ch;
	unsigned int		un;
	size_t				i;

	un = n;
	i = ft_len(n);
	if (n < 0)
	{
		un = -un;
		i++;
	}
	if (!(ch = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ch[i] = '\0';
	ch[--i] = (un % 10) + '0';
	while (un /= 10)
		ch[--i] = (un % 10) + '0';
	if (n < 0)
		ch[0] = '-';
	return (ch);
}
