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

int	main()
{
	int fd;
	char *line;
	char **p_line;
	
	line = NULL;
        p_line = &line;
	fd = open("test1.txt", O_RDONLY);

	get_next_line(fd, p_line);
//	printf("line_ = %d\n", *line);

	get_next_line(fd, p_line);
//	printf("line_ = %d\n", *line);

	get_next_line(fd, p_line);
//	printf("line_ = %d\n", *line);

	get_next_line(fd, p_line);
//	printf("line_ = %d\n", *line);
	return (0);
}
