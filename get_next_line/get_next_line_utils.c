/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/25 13:54:13 by mlaouedj         ###   ########.fr       */
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

int		fdcurs(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_cat(char *dst, char *src, int n)
{
	int i;
	int j;
	int k;
	char *tmp;

	i = 0;
	j = ft_strlen(dst);
	k = 0;
	if (!(tmp = ft_strdup(dst)))
		return (NULL);
	if (src[k] == '\n')
		k++;
	free(dst);
	if (!(dst = malloc(sizeof(char) * (ft_strlen(tmp) + n + 1))))
		return (NULL);
	while (tmp[i])
	{
		dst[i] = tmp[i];
		i++;
	}
	free(tmp);
	i = 0;
	while ((i + k) < n)
	{
		dst[j + i] = src[k + i];
		i++;	
	}
	dst[j + i] = '\0';
	return (dst);
}

char	*ft_strdup(char *s)
{
	int i;
	char *dst;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
