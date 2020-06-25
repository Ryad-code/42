/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:35:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/25 16:19:12 by mlaouedj         ###   ########.fr       */
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
		obj.res = ft_rest(&rest, line, obj);
		if (obj.res == -1)
			return (-1);
		if (obj.res == 1)
			return (1);
	}
	
	if ((obj.res = read(fd, buff, BUFFER_SIZE)) < 0)
		return (-1);
	buff[obj.res] = '\0';
	if (!(*line = ft_cat(*line, buff, fdcurs(buff))))
		return (-1);
	while (fdcurs(buff) == obj.res)
	{
		if ((obj.res = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		if (obj.res == 0)
			return (0);
		buff[obj.res] = '\0';
		if (!(*line = ft_cat(*line, buff, fdcurs(buff))))
			return (-1);
	}
	if (fdcurs(buff) != obj.res)
	{
		if (!(rest = ft_strdup("")))
			return (-1);
		if (!(rest = ft_cat(rest, &buff[fdcurs(buff)], (obj.res - fdcurs(buff)))))
			return (-1);
	}
	return (1);
}
