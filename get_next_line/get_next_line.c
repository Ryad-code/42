/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:35:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/03 17:50:36 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE];
	char		*temp;
	static char	*rest;

	if (BUFFER_SIZE == 0)
		return (-1);
	if (rest)
	{
		if (!(temp = malloc(sizeof(char) *
		(ft_checkend(rest, ft_strlen(rest)) + 1))))
			return (-1);
		temp[0] = '\0';
		ft_strncat(temp, rest, ft_checkend(rest, ft_strlen(rest)));
		if (ft_checkend(rest, ft_strlen(rest)) < ft_strlen(rest))
		{
			if (!(*line = malloc(sizeof(char) * (ft_strlen(temp) + 1))))
				return (-1);
			*line[0] = '\0';
			ft_strncat(*line, temp, ft_checkend(rest, ft_strlen(rest)));
			rest = ft_getrest(rest, ft_checkend(rest, ft_strlen(rest)));
			return (1);
		}
	}
	read(fd, buffer, BUFFER_SIZE);
	if (rest)
	{
		if (!(*line = malloc(sizeof(char) *
		(ft_strlen(temp) + ft_checkend(buffer, BUFFER_SIZE) + 1))))
			return (-1);
		*line[0] = '\0';
		ft_strncat(*line, temp, ft_strlen(temp));
		free(temp);
	}
	else
	{
		*line = malloc(sizeof(char) * (ft_checkend(buffer, BUFFER_SIZE) + 1));
		*line[0] = '\0';
	}
	ft_strncat(*line, buffer, ft_checkend(buffer, BUFFER_SIZE));
	if (ft_checkend(buffer, BUFFER_SIZE) < BUFFER_SIZE)
		if (!(rest = ft_getrest(buffer, ft_checkend(buffer, BUFFER_SIZE))))
			return (-1);
	while (ft_checkend(buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		read(fd, buffer, BUFFER_SIZE);
		if (!(*line = ft_setline(*line, buffer,
		ft_checkend(buffer, BUFFER_SIZE))))
			return (-1);
		if (ft_checkend(buffer, BUFFER_SIZE) < BUFFER_SIZE)
			if (!(rest = ft_getrest(buffer, ft_checkend(buffer, BUFFER_SIZE))))
				return (-1);
	}
	if (buffer[ft_checkend(buffer, BUFFER_SIZE)] == EOF)
		return (0);
	return (1);
}
