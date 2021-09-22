/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:42:09 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/21 17:40:08 by mlaouedj         ###   ########.fr       */
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
# define BUFFER_SIZE 1024

typedef struct s_line
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			res;
	int			res1;
}				t_line;
int				ft_strlen(char *s);
int				fdcurs(char *s);
int				ft_rest(char **rest, char **line, t_line obj);
char			*ft_cat(char *dst, const char *src, int n);
char			*ft_strdup(char *s);
int				get_next_line(int fd, char **line);
int				get_line(int fd, t_line *obj, char **line);
int				ft_main(int fd, char **line, char **rest, t_line *obj);

#endif
