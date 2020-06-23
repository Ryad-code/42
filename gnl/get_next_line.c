/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:12:58 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/23 16:28:58 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_start(char *buff, char *line, char *rest)
{
	if (rest)
	{
		if (!(line = set_line(line, buff, fdcurs(buff))))
			return (NULL);
	}
	else
	{
		if (!(line = malloc(sizeof(char) * (fdcurs(buff) + 1))))
			return (NULL);
		line[0] = '\0';
		ft_cat(line, buff, fdcurs(buff));
	}
	return (line);
}

char	*ft_set(char *dst, char *src, int n)
{
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * (n + 1))))
		return (dst);
	dst[0] = '\0';
	ft_cat(dst, src, n);
	return (dst);
}



int		get_next_line(int fd, char **line)
{
	int				res;
	char			buff[BUFFER_SIZE + 1];
	static	char	*rest;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (rest)
	{
		if (!(*line = ft_set(*line, rest, fdcurs(rest))))
			return (-1);
		if (fdcurs(rest) != ft_strlen(rest))
		{
			if (!(rest = set_rest(rest)))
				return (-1);
			return (1);
		}
		free(rest);
	}
//..........................................................................
	res = read(fd, buff, BUFFER_SIZE);
	buff[res] = '\0';
	if (!(*line = ft_start(buff, *line, rest)))
		return (-1);
//..........................................................................
	while (fdcurs(buff) == res)
	{
		res = read(fd, buff, BUFFER_SIZE);
		buff[res] = '\0';
		if (!(*line = set_line(*line, buff, fdcurs(buff))))
			return (-1);
		if (res == 0)
			return (0);
	}
//..........................................................................
	if (fdcurs(buff) != res)
		if (!(rest = ft_set(rest, &buff[fdcurs(buff)], (res - fdcurs(buff)))))
			return (-1);
	return (1);
}
