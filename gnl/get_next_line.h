
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);
int		fdcurs(char *s);
int		ft_cat(char *dst, char *src, int len);
char	*ft_start(char *buff, char *ine, char *rest);
char	*set_line(char *dst, char *src, int curs);
char    *set_rest(char *rest);

#endif
