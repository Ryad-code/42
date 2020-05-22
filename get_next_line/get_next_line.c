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

int	ft_strlen(char *s);

int	get_next_line(int fd, char **line)
{
	int	BUFF_size;
	void	*p;
	char 	*p1;

	BUFF_size = 3;
	p = (void *)*line;
	p1 = *line;
	while (ft_checkend(p1) == 1)
	{
		line = malloc(sizeof(char) * BUFF_size);
		read(fd, p, BUFF_size);
		p = (p++);
		p1 = (p1++);
		printf("%s\n", p1);
		printf("%d\n", ft_checkend(p1));
	}


	return (25);
}
