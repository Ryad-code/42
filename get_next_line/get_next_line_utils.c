/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:10:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/17 14:10:42 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_checkend_b(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int     ft_checkend_f(char *s, int size)
{
	int i;
	i = 0;
	while (i < size)
	{
		if (s[i] == EOF)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dst, const char *src, int n)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(dst);
	while (i < n && src[i]) 
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (dst);
	
}

char	*ft_getend(char *src, int n)
{
	int i;
	char *dst;

	i = 0;
	dst = malloc(sizeof(char) * (BUFF_SIZE - n));
	while (i < (BUFF_SIZE - n))
	{
		dst[i] = src[i + n];
		i++;
	}
	dst[i] = '\0';		// Uniquement pour l'affichage
	return (dst);
}
