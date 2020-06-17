/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:09:43 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/17 17:15:18 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		fdcurs(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s[i] == '\n')
			return (i);
		if (s[i] == EOF)
			return (-1);
		i++;
	}
	return (i);
}

char	*setline(char *dst, char *src, int n)
{
	int i;

	i = 0;
	dst = NULL;
	dst = malloc(sizeof(char) * (n + 1));
	while (i  < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*setrest(char *dst, char *src, int n)
{
	int i;

	i = 0;
	dst = NULL;
	dst = malloc(sizeof(char) * ((BUFFER_SIZE - n) + 1));
	while ((n + i) != BUFFER_SIZE)
	{
		dst[i] = src[n + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_cat(char *dst, char *src , int n)
{		
	int i;
	int j;

	i = 0;
	j = ft_strlen(dst);
	while (i < n)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (i);
}
