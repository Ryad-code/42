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
	char buffer[BUFF_SIZE];
	char *dst;
	char *tmp = "bonjour";

	cursor = 0;
	buffer[0] = '\0';
	dst = NULL;
	dst = malloc(sizeof(char) * 40);
	if (BUFF_SIZE == 0)					// Si BUFF_SIZE est nul
		return (0);
	read(fd, buffer, BUFF_SIZE);				// Premier read dans le buffer
	ft_strncat(dst, buffer, BUFF_SIZE);
	while (ft_checkend_b(buffer, BUFF_SIZE) == 0)	// Boucle de read en cas de buffer trop petit
	{
		read(fd, buffer, BUFF_SIZE);
		cursor = ft_checkend_b(buffer, BUFF_SIZE);
		printf("%d\n", cursor);
		if (cursor == 0)
			printf("%s\n", ft_strncat(dst, buffer, BUFF_SIZE));
		else
		printf("%s\n", ft_strncat(dst, buffer, cursor));		
	}
	printf("%s\n", dst);
	return (1);
}
