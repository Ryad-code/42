
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			curs;
	int			res;
	char		buff[BUFFER_SIZE + 1];
	static	char	*rest;
	if (BUFFER_SIZE < 1)
		return (-1);
	if (rest)
	{
		curs = fdcurs(rest);
		*line = malloc(sizeof(char) * (curs + 1));
		*line[0] = '\0';
		ft_cat(*line, rest, curs);
		if (curs != ft_strlen(rest))
		{
			rest = set_rest(rest);
			return (1);
		}
		free(rest);
	}
//..........................................................................
	res = read(fd, buff, BUFFER_SIZE);
	buff[res] = '\0';
	curs = fdcurs(buff);
	if (rest)
		*line = set_line(*line, buff, curs);
	else
	{
		*line = malloc(sizeof(char) * (curs + 1));
		*line[0] = '\0';
		ft_cat(*line, buff, curs);
	}
//..........................................................................
	while (curs == res)
	{
		res = read(fd, buff, BUFFER_SIZE);
		buff[res] = '\0';
		curs = fdcurs(buff);
		*line = set_line(*line, buff, curs);
		if (res == 0)
			return (0);
	}
//..........................................................................
	if (curs != res)
	{
		rest = malloc(sizeof(char) * (res - curs + 1));
		rest[0] = '\0';
		ft_cat(rest, &buff[curs], (res - curs));
	}
	return (1);
}
