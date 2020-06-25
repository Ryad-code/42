/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:35:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/25 14:02:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	static char	*rest;
	s_line obj;

	if (fd < 0 || BUFFER_SIZE == 0 || (!line))
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (rest)
	{
		if (!(*line = ft_cat(*line, rest, fdcurs(rest))))
			return (-1);
		if (fdcurs(rest) != ft_strlen(rest))
		{
			if (!(obj.tmp = ft_strdup(rest)))
				return (-1);
			free(rest);
			if (!(rest = ft_strdup("")))
				return (-1);
			if (!(rest = ft_cat(rest, &obj.tmp[fdcurs(obj.tmp)], (ft_strlen(obj.tmp) - fdcurs(obj.tmp)))))
				return (-1);
			free(obj.tmp);
			printf("rest_ = %s\n", rest);
			return (1);
		}
		free(rest);
	}	
	obj.res = read(fd, buff, BUFFER_SIZE);
	buff[obj.res] = '\0';
	if (!(*line = ft_cat(*line, buff, fdcurs(buff))))
		return (-1);
	while (fdcurs(buff) == obj.res)
	{
		obj.res = read(fd, buff, BUFFER_SIZE);
		buff[obj.res] = '\0';
		if (!(*line = ft_cat(*line, buff, fdcurs(buff))))
			return (-1);
		if (obj.res == 0)
			return (0);
	}
	if (fdcurs(buff) != obj.res)
	{
		rest = ft_strdup("");
		if (!(rest = ft_cat(rest, &buff[fdcurs(buff)], (obj.res - fdcurs(buff)))))
			return (-1);
	}
	printf("rest = %s\n", rest);
	return (1);
}
