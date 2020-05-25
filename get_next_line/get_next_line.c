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
	int cursor;
	int nb_buffer;
	char buffer[BUFF_SIZE];
	char *dst;

	cursor = 0;
	buffer[0] = '\0';
	if (BUFF_SIZE == 0)					// Si BUFF_SIZE est nul
		return (0);
	nb_buffer = 1;
	read(fd, buffer, BUFF_SIZE);				// Premier read dans le buffer
	printf("%s\n", buffer);
	while (ft_checkend_b(buffer, BUFF_SIZE) == BUFF_SIZE)	// Boucle de read en cas de buffer trop petit
	{
		read(fd, buffer, BUFF_SIZE);
		nb_buffer++;
		printf("%s\n", buffer);
		printf("%d\n", ft_checkend_b(buffer, BUFF_SIZE));
	}
	cursor = ft_checkend_b(buffer, BUFF_SIZE);
	printf("%d\n", cursor);
	return (1);
}
