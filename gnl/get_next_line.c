
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			res;
	char		buff[BUFFER_SIZE + 1];
	static	char	*rest;
	if (BUFFER_SIZE < 1)
		return (-1);
	if (rest)
	{
		*line = malloc(sizeof(char) * (fdcurs(rest) + 1));
		*line[0] = '\0';
		ft_cat(*line, rest, fdcurs(rest));
		if (fdcurs(rest) != ft_strlen(rest))
		{
			rest = set_rest(rest);
			return (1);
		}
		free(rest);
	}
//..........................................................................
	res = read(fd, buff, BUFFER_SIZE);
	buff[res] = '\0';
	if (rest)
		*line = set_line(*line, buff, fdcurs(buff));
	else
	{
		*line = malloc(sizeof(char) * (fdcurs(buff) + 1));
		*line[0] = '\0';
		ft_cat(*line, buff, fdcurs(buff));
	}
//..........................................................................
	while (fdcurs(buff) == res)
	{
		res = read(fd, buff, BUFFER_SIZE);
		buff[res] = '\0';
		*line = set_line(*line, buff, fdcurs(buff));
		if (res == 0)
			return (0);
	}
//..........................................................................
	if (fdcurs(buff) != res)
	{
		rest = malloc(sizeof(char) * (res - fdcurs(buff) + 1));
		rest[0] = '\0';
		ft_cat(rest, &buff[fdcurs(buff)], (res - fdcurs(buff)));
	}
	return (1);
}
