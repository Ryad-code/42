
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			curs;
	int			res;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	static	char	*rest;

	if (rest)
	{
		curs = fdcurs(rest);
		*line = malloc(sizeof(char) * (curs + 1));
		*line[0] = '\0';
		ft_cat(*line, rest, curs);
		if (curs != ft_strlen(rest))
		{
			tmp = malloc(sizeof(char) * (ft_strlen(rest) - curs + 1));
			tmp[0] = '\0';
			ft_cat(tmp, &rest[curs], (ft_strlen(rest) - curs + 1));
			free(rest);
			rest = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
			rest[0] = '\0';
			ft_cat(rest, tmp, ft_strlen(tmp));
			free(tmp);
			printf("line_ = %s\n", *line);
			printf("rest_ = %s\n\n", rest);
			return (1);
		}
		free(rest);
	}
//..........................................................................
	res = read(fd, buff, BUFFER_SIZE);
	buff[res] = '\0';
	curs = fdcurs(buff);
//..........................................................................
	if (rest)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(*line) + 1));
		tmp[0] = '\0';
		ft_cat(tmp, *line, ft_strlen(*line));
		free(*line);
		*line = malloc(sizeof(char) * (ft_strlen(tmp) + curs + 1));
		*line[0] = '\0';
		ft_cat(*line, tmp, ft_strlen(tmp));
		free(tmp);
		ft_cat(*line, buff, curs);
	}
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
		tmp = malloc(sizeof(char) * (ft_strlen(*line) + 1));
		tmp[0] = '\0';
		ft_cat(tmp, *line, ft_strlen(*line));
		free(*line);
		*line = malloc(sizeof(char) * (ft_strlen(tmp) + curs + 1));
		*line[0] = '\0';
		ft_cat(*line, tmp, ft_strlen(tmp));
		free(tmp);
		ft_cat(*line, buff, curs);
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
	printf("line = %s\n", *line);
	printf("rest = %s\n\n", rest);
	free(*line);
	return (1);
}
