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
	static char *tmp;

	cursor = 0;
	buffer[0] = '\0';
	dst = NULL;
	dst = malloc(sizeof(char) * 100);
	tmp = NULL;
	if (BUFF_SIZE == 0)					// Si BUFF_SIZE est nul
		return (0);
	read(fd, buffer, BUFF_SIZE);				// Premiere lecture dans le buffer
	cursor = ft_checkend_b(buffer, BUFF_SIZE);
	if (cursor > 0)						// On concatène en fonction de la taille du buffer
	{
		ft_strncat(dst, buffer, cursor);
		tmp = ft_getend(buffer, cursor);
	}
	else
		ft_strncat(dst, buffer, BUFF_SIZE);
	printf("%d\n", cursor);
	while (ft_checkend_b(buffer, BUFF_SIZE) == 0)		// Boucle de read
	{
		read(fd, buffer, BUFF_SIZE);
		cursor = ft_checkend_b(buffer, BUFF_SIZE);
		printf("%d\n", cursor);
		if (cursor == 0)
			ft_strncat(dst, buffer, BUFF_SIZE);
		else
		{
			ft_strncat(dst, buffer, cursor);
			tmp = ft_getend(buffer, cursor);
		}
	}
	printf("%s\n", dst);
	printf("Tmp = %s\n", tmp);
	return (1);
}
