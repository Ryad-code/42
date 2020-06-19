
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int curs;
	char *buff;
	char *rest;
	
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	
	read(fd, buff, BUFFER_SIZE);
	curs = fdcurs(buff, BUFFER_SIZE);

	*line = malloc(sizeof(char) * (curs + 1));
	*line[0] = '\0';
	ft_cat(*line, buff, curs);

	if (curs < BUFFER_SIZE)
	{
		rest = malloc(sizeof(char) * (BUFFER_SIZE - curs + 1));
		rest[0] = '\0';
		ft_cat(rest, &buff[curs], (BUFFER_SIZE - curs));
	}
	else
	{
		return (0);
	}
	printf("line = %s\n", *line);
	printf("rest = %s\n", rest);
	free(buff);
	free(*line);
	free(rest);
	return (0);
}
