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
	char	buff[BUFFER_SIZE + 1];
	static char	*rest;
	s_line obj;

	obj.dst = ft_strdup("");
	if (rest)
	{
		obj.dst = ft_cat(obj.dst, rest, fdcurs(rest));
		if (fdcurs(rest) != ft_strlen(rest))
		{
			obj.tmp = ft_strdup(rest);
			free(rest);
			rest = ft_strdup("");
			rest = ft_cat(rest, &obj.tmp[fdcurs(obj.tmp)], (ft_strlen(obj.tmp) - fdcurs(obj.tmp)));
			free(obj.tmp);
			printf("dst_ = %s\n", obj.dst);
			printf("rest_ = %s\n\n", rest);
			return (1);
		}
		free(rest);
	}
		
	obj.res = read(fd, buff, BUFFER_SIZE);
	obj.curs = fdcurs(buff);
	buff[obj.res] = '\0';
	obj.dst = ft_cat(obj.dst, buff, obj.curs);
	
	while (obj.curs == obj.res)
	{
		obj.res = read(fd, buff, BUFFER_SIZE);
		obj.curs = fdcurs(buff);
		obj.dst = ft_cat(obj.dst, buff, obj.curs);
	}

	if (obj.curs != obj.res)
	{
		rest = ft_strdup("");
		rest = ft_cat(rest, &buff[obj.curs], (obj.res - obj.curs));
	}
	
	printf("dst = %s\n", obj.dst);
	printf("rest = %s\n\n", rest);
	return (1);
}
