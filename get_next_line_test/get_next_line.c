/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:09:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/18 14:11:07 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE];
	char	*tmp;
	static	char	*rest;

	tmp = NULL;
	if (BUFFER_SIZE == 0)
		return (-1);
	if (rest)
	{
		if (fdcurs(rest, ft_strlen(rest)) < ft_strlen(rest))
		{
			if (!(*line = setline(*line, rest, fdcurs(rest, ft_strlen(rest)))))
				return (-1);
			if (!(tmp = setrest(tmp, rest, fdcurs(rest, ft_strlen(rest)), (ft_strlen(rest) - fdcurs(rest, ft_strlen(rest))))))
				return (-1);
			free(rest);
			if (!(rest = ft_swap(rest, tmp)))
				return (-1);
			free(tmp);
			return (0);	
		}
		else
		{
			*line = malloc(sizeof(char) * (ft_strlen(rest) + 1));
			*line[0] = '\0';
			ft_cat(*line, rest, ft_strlen(rest));
			free(rest);
		}
	}
//..............................................................................	
	read(fd, buff, BUFFER_SIZE);
	if (rest)
	{
		tmp = ft_swap(tmp, *line);
		free(*line);
		*line = malloc(sizeof(char) * (ft_strlen(tmp) + fdcurs(buff, BUFFER_SIZE) + 1));
		*line[0] = '\0';
		ft_cat(*line, tmp, ft_strlen(tmp));
		free(tmp);
		ft_cat(*line, buff, fdcurs(buff, BUFFER_SIZE));
	}
	else
	{
		if (!(*line = setline(*line, buff, fdcurs(buff, BUFFER_SIZE))))
		return (-1);
	}
//..............................................................................
	if (fdcurs(buff, BUFFER_SIZE) < BUFFER_SIZE)
	{
		if (!(rest = setrest(rest, buff, fdcurs(buff, BUFFER_SIZE), BUFFER_SIZE - fdcurs(buff, BUFFER_SIZE))))
			return (-1);
	}
	else
	{
		if (!(*line = ft_loop(fd, buff, *line)))
			return (-1);
			if (fdcurs(buff, BUFFER_SIZE) != BUFFER_SIZE)
				rest = setrest(rest, buff, fdcurs(buff, BUFFER_SIZE), (BUFFER_SIZE - fdcurs(buff, BUFFER_SIZE)));

	}
	return (0);
}
