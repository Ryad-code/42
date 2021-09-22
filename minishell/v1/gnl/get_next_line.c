/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:35:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/26 14:50:21 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(int fd, t_line *obj, char **line)
{
	if ((obj->res = read(fd, obj->buff, BUFFER_SIZE)) < 0)
		return (-1);
	obj->buff[obj->res] = '\0';
	if (!(*line = ft_cat(*line, obj->buff, fdcurs(obj->buff))))
		return (-1);
	while (fdcurs(obj->buff) == obj->res)
	{
		if ((obj->res = read(fd, obj->buff, BUFFER_SIZE)) < 0)
			return (-1);
		if (obj->res == 0)
			return (0);
		obj->buff[obj->res] = '\0';
		if (!(*line = ft_cat(*line, obj->buff, fdcurs(obj->buff))))
			return (-1);
	}
	return (1);
}

int	ft_main(int fd, char **line, char **rest, t_line *obj)
{
	if ((obj->res1 = get_line(fd, obj, line)) == -1)
		return (-1);
	if (obj->res1 == 0)
		return (0);
	if (fdcurs(obj->buff) != obj->res)
	{
		if (!(*rest = ft_strdup("")))
			return (-1);
		if (!(*rest = ft_cat(*rest, &obj->buff[fdcurs(obj->buff)],
		(obj->res - fdcurs(obj->buff)))))
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest;
	t_line		obj;

	if (fd < 0 || BUFFER_SIZE == 0 || (!line))
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	obj.tmp = NULL;
	if (rest)
	{
		obj.res = ft_rest(&rest, line, obj);
		if (obj.res == -1)
			return (-1);
		if (obj.res == 1)
			return (1);
	}
	if ((obj.res1 = ft_main(fd, line, &rest, &obj)) == -1)
		return (-1);
	if (obj.res1 == 0)
		return (0);
	return (1);
}
