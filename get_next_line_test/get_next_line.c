
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int curs;
	int res;
	char *buff;
	static	char *rest;
	char	*tmp;
	
	if (BUFFER_SIZE == 0)
		return (-1);
//..................................................................
	if (rest)
	{
		curs = fdcurs(rest, ft_strlen(rest));
		*line = malloc(sizeof(char) * (curs + 1));
		*line[0] = '\0';
		ft_cat(*line, rest, curs);
		if (curs < ft_strlen(rest))
		{
			tmp = malloc(sizeof(char) * (ft_strlen(rest) - curs + 1));
			tmp[0] = '\0';
			ft_cat(tmp, &rest[curs], (ft_strlen(rest) - curs));
			free(rest);
			rest = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
			rest[0] = '\0';
			ft_cat(rest, tmp, ft_strlen(tmp));
			printf("line = %s\n", *line);
			printf("rest = %s\n", rest);
			return (0);
		}
	}
//..................................................................
	buff = malloc(sizeof(char) * BUFFER_SIZE);	
	res = read(fd, buff, BUFFER_SIZE);
	curs = fdcurs(buff, BUFFER_SIZE);

	*line = malloc(sizeof(char) * (curs + 1));
	*line[0] = '\0';
	ft_cat(*line, buff, curs);
//..................................................................
	while (curs == BUFFER_SIZE)
	{
		res = read(fd, buff, BUFFER_SIZE);
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
	printf("line_ = %s\n", *line);
	printf("rest_ = %s\n", rest);
	free(buff);
	free(*line);
	return (0);
}
