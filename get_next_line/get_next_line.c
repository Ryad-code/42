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
	char *tmp;
	static char *rest;

	buffer[0] = '\0';
	tmp = NULL;
	tmp = malloc(sizeof(char) * 100);
	if (BUFFER_SIZE == 0)
		return (-1);
	if (rest != NULL)
	{
		cursor = ft_checkend(rest, ft_strlen(rest));
		ft_strncat(tmp, rest, cursor);
		if (cursor != ft_strlen(rest))
		{
			rest = ft_getend(rest, cursor);
			printf("tmp = %s\n", tmp);
//			printf("rest = %s\n", rest);
			return (1);
		}
	}
	read(fd, buffer, BUFFER_SIZE);
	cursor = ft_checkend(buffer, BUFFER_SIZE);
	if (cursor != BUFFER_SIZE)
	{
		ft_strncat(tmp, buffer, cursor);
		rest = ft_getend(buffer, cursor);
	}
	else
		ft_strncat(tmp, buffer, BUFFER_SIZE);
	while (cursor == BUFFER_SIZE)
	{
		read(fd, buffer, BUFFER_SIZE);
		cursor = ft_checkend(buffer, BUFFER_SIZE);
		if (cursor == BUFFER_SIZE)
			ft_strncat(tmp, buffer, BUFFER_SIZE);
		else
		{
			ft_strncat(tmp, buffer, cursor);
			rest = ft_getend(buffer, cursor);
		}
	}
	printf("tmp = %s\n", tmp);
//	printf("rest = %s\n", rest);
	return (1);
}
