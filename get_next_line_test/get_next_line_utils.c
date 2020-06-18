/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:09:43 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/18 14:00:29 by mlaouedj         ###   ########.fr       */
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
	if (!(dst = malloc(sizeof(char) * (n + 1))))
		return (dst);
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
	while (src[n] == '\n')
		n++;
	if (!(dst = malloc(sizeof(char) * ((BUFFER_SIZE - n) + 1))))
		return (dst);
	while (i < (BUFFER_SIZE - n))
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

char	*ft_loop(int fd, char *buff, char *dst)
{
	char *tmp;
	
	tmp = NULL;
	while (fdcurs(buff, BUFFER_SIZE) == BUFFER_SIZE)
	{
//		free(buff);
//		buff = malloc(sizeof(char) * BUFFER_SIZE);
		read(fd, buff, BUFFER_SIZE);
		if (!(tmp = malloc(sizeof(char) * (ft_strlen(dst) + 1))))
			return (NULL);
		tmp[0] = '\0';
		ft_cat(tmp, dst, ft_strlen(dst));
		free(dst);
		if (!(dst = malloc(sizeof(char) * (ft_strlen(tmp) + BUFFER_SIZE + 1))))
			return (NULL);
		dst[0] = '\0';
		ft_cat(dst, tmp, ft_strlen(tmp));
		free(tmp);
		ft_cat(dst, buff, fdcurs(buff, BUFFER_SIZE));
	}
	return (dst);
}

char	*ft_swap(char *dst, char *src)
{
	int i;

	i = 0;
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (dst);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


