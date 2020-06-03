#include "get_next_line.h"

int	main()
{
	int fd;
	int res;
	char *line;
	char **p_line;

	line = NULL;
	p_line = &line;
	fd = open("test.txt", O_RDONLY);

	res = get_next_line(fd, p_line);
	printf("%s\n", line);

	res = get_next_line(fd, p_line);
	printf("%s\n", line);

	res = get_next_line(fd, p_line);
	printf("%s\n", line);

	res = get_next_line(fd, p_line);
	printf("%s\n", line);

	res = get_next_line(fd, p_line);
	printf("%s\n", line);

	printf("%d\n", res);
}
