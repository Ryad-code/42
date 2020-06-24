
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct	t_line
{
	char	buff[BUFFER_SIZE + 1];
	char	*dst;
	char	*tmp;
	int 	res;
	int	curs;
}			s_line;

int	ft_strlen(char *s);
int	fdcurs(char *s);
char	*ft_cat(char *dst, char *src, int n);
char	*ft_strdup(char *s);

int	get_next_line(int fd, char **line);

#endif
