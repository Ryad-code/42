/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:42:09 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/26 13:48:00 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	t_line
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		res;
	int		res1;
}				s_line;
int		ft_strlen(char *s);
int		fdcurs(char *s);
int		ft_rest(char **rest, char **line, s_line obj);
char	*ft_cat(char *dst, const char *src, int n);
char	*ft_strdup(char *s);
int		get_next_line(int fd, char **line);
#endif
