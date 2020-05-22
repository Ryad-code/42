/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:12:31 by ryad              #+#    #+#             */
/*   Updated: 2020/05/17 16:55:33 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line);

int	main()
{
	int fd;
	char line[3];
	char *p_line;
	char **p;

	fd = open("test.txt", O_RDONLY);
	p_line = &line[0];
	p = &p_line;

//	printf("%s\n", p_line);
	printf("%d\n", get_next_line(fd, p));
//	printf("%s\n", p_line);
//	printf("%d\n", ft_strlen(p_line)); 

	return (0);
}
