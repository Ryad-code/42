#include "get_next_line.h"

int	main()
{
	int fd;
	char *line;
	char **p_line;

	line = NULL;
	p_line = &line;
	fd = open("test.txt", O_RDONLY);


	printf("%d\n", get_next_line(fd, p_line));
	printf("%s\n", line);

	printf("%d\n", get_next_line(fd, p_line));
	printf("%s\n", line);

	printf("%d\n", get_next_line(fd, p_line));
	printf("%s\n", line);
	
	printf("%d\n", get_next_line(fd, p_line));
	printf("%s\n", line);	

	printf("%d\n", get_next_line(fd, p_line));
}
