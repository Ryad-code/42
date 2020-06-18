/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:14:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/18 12:51:23 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
	int fd;
	char *line;
	char **p_line;

	fd = open("test.txt", O_RDONLY);
	line = NULL;
	p_line = &line;

	printf("return = %d\n", get_next_line(fd, p_line));
	printf("%s\n\n", line);

	printf("return = %d\n", get_next_line(fd, p_line));
	printf("%s\n\n", line);

	printf("return = %d\n", get_next_line(fd, p_line));
	printf("%s\n\n", line);

	printf("return = %d\n", get_next_line(fd, p_line));
	printf("%s\n\n", line);
}
