/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:03:50 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/17 17:18:41 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int cursor;
	char buffer[BUFFER_SIZE];
	char *temp;
	static char *rest;

	buffer[0] = '\0';
	*line = NULL;
	temp = NULL;
	if (BUFFER_SIZE == 0)
		return (-1);
	if (rest)
	{
		cursor = ft_checkend(rest, ft_strlen(rest));
		temp = malloc(sizeof(char) * (cursor + 1));
		ft_strncat(temp, rest, cursor);
		if (cursor < ft_strlen(rest))
		{
			*line = malloc(sizeof(char) * (ft_strlen(temp) + 1));
			ft_strncat(*line, temp, cursor);
			rest = ft_getend(rest, cursor);
			printf("line_ = %s\n", *line);
			return (1);
		}
	}
//.................................................................................

	read(fd, buffer, BUFFER_SIZE);
	cursor = ft_checkend(buffer, BUFFER_SIZE);
	if (rest)
	{
		*line = malloc(sizeof(char) * (ft_strlen(temp) + cursor + 1));
		ft_strncat(*line, temp, ft_strlen(temp));
		free(temp);
	}
	else
	{
		*line = malloc(sizeof(char) * (cursor + 1));
		*line[0] = '\0';
	}
	ft_strncat(*line, buffer, cursor); 

//................................................................................. 
 	
	if (cursor < BUFFER_SIZE)
		rest = ft_getend(buffer, cursor);
	while (cursor == BUFFER_SIZE)
	{
		read(fd, buffer, BUFFER_SIZE);
		cursor = ft_checkend(buffer, BUFFER_SIZE);
		temp = malloc(sizeof(char) * (ft_strlen(*line) + cursor + 1));
		ft_strncat(temp, *line, ft_strlen(*line));
		ft_strncat(temp, buffer, cursor);
		free(*line);
		*line = malloc(sizeof(char) * (ft_strlen(temp) + cursor + 1));
		ft_strncat(*line, temp, ft_strlen(temp));
		free(temp);
		if (cursor < BUFFER_SIZE)
		{
			rest = ft_getend(buffer, cursor);
		}
	}
	printf("line = %s\n", *line);
	return (1);
}
