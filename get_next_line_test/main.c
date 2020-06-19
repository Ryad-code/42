
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	char **p_line;

	fd = open("test.txt", O_RDONLY);
	line = NULL;
	p_line = &line;

	get_next_line(fd, p_line);

	return (0);
}
