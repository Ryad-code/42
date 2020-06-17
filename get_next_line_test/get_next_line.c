/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:09:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/17 17:16:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE];
	char	*tmp;
	static	char	*rest;

	read(fd, buff, BUFFER_SIZE);
	if (fdcurs(buff, BUFFER_SIZE) < BUFFER_SIZE)
	{
		*line = setline(*line, buff, fdcurs(buff, BUFFER_SIZE));
		rest = setrest(rest, buff, fdcurs(buff, BUFFER_SIZE));
	}
	else
	{
		*line = setline(*line, buff, BUFFER_SIZE);
		while (fdcurs(buff, BUFFER_SIZE) == BUFFER_SIZE)
			{
				read(fd, buff, BUFFER_SIZE);
				tmp = malloc(sizeof(char) * (ft_strlen(*line) + 1));
				tmp[0] = '\0';
				ft_cat(tmp, *line, BUFFER_SIZE);
				free(*line);
				*line = malloc(sizeof(char) * (ft_strlen(tmp) + BUFFER_SIZE + 1));
				ft_cat(*line, tmp, BUFFER_SIZE);
			}
	}
	printf("%s\n", *line);
	printf("%s\n", rest);	
	return (0);
}
