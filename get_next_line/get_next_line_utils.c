/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/03 17:00:37 by mlaouedj         ###   ########.fr       */
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

int		ft_checkend(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s[i] == '\n' || s[i] == EOF)
			return (i);
		i++;
	}
	return (i);
}

int		ft_strncat(char *dst, char *src, int n)
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

char	*ft_getrest(char *s, int n)
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	while (s[n] == '\n')
		n++;
	if (!(dst = malloc(sizeof(char) * ((BUFFER_SIZE - n) + 1))))
		return (dst);
	while (i < BUFFER_SIZE - n)
	{
		dst[i] = s[i + n];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_setline(char *dst, char *src, int n)
{
	char *temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(char) * (ft_strlen(dst) + n + 1))))
		return (temp);
	temp[0] = '\0';
	ft_strncat(temp, dst, ft_strlen(dst));
	ft_strncat(temp, src, n);
	free(dst);
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(temp) + n + 1))))
		return (dst);
	dst[0] = '\0';
	ft_strncat(dst, temp, ft_strlen(temp));
	free(temp);
	return (dst);
}
