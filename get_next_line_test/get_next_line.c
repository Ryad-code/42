
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int curs;
	int res;
	char *buff;
	static	char *rest;
	
	if (BUFFER_SIZE == 0)
		return (-1);
//..................................................................
	if (rest)
	{
		
	}
//..................................................................
	buff = malloc(sizeof(char) * BUFFER_SIZE);	
	res = read(fd, buff, BUFFER_SIZE);
	if (res == -1)
		return (-1);
	curs = fdcurs(buff, BUFFER_SIZE);

	*line = malloc(sizeof(char) * (curs + 1));
	*line[0] = '\0';
	ft_cat(*line, buff, curs);
//..................................................................
	while (curs == BUFFER_SIZE)
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
			return (-1);
		curs = fdcurs(buff, BUFFER_SIZE);
		*line = ft_swap(*line, buff, curs);
	}
//..................................................................
	if (curs < BUFFER_SIZE && res != 0)
	{
		rest = malloc(sizeof(char) * (BUFFER_SIZE - curs + 1));
		rest[0] = '\0';
		ft_cat(rest, &buff[curs], (BUFFER_SIZE - curs));
	}
	if (res == 0)
		return (1);
	printf("curs = %d\n", curs);
	printf("line_ = %s\n", *line);
	printf("rest = %s\n", rest);
	free(buff);
	free(*line);
	return (0);
}
