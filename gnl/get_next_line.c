/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:12:58 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/23 15:13:01 by mlaouedj         ###   ########.fr       */
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

int		get_next_line(int fd, char **line)
{
	int				res;
	char			buff[BUFFER_SIZE + 1];
	static	char	*rest;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (rest)
	{
		if (!(*line = malloc(sizeof(char) * (fdcurs(rest) + 1))))
			return (-1);
		*line[0] = '\0';
		ft_cat(*line, rest, fdcurs(rest));
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
	{
		if (!(rest = malloc(sizeof(char) * (res - fdcurs(buff) + 1))))
			return (-1);
		rest[0] = '\0';
		ft_cat(rest, &buff[fdcurs(buff)], (res - fdcurs(buff)));
	}
	return (1);
}
