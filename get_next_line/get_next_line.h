
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_strlen(char *s);
int	get_next_line(int fd, char **line);
int	ft_checkend(char *s, int n);
char	*ft_getrest(char *s, int n);
char	*ft_setline(char *dst, char *src, int n);
int	ft_strncat(char *dst, char *src, int n);

#endif
