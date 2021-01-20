#include "../cub3d.h"

int	ft_atoi(char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

void	ft_read_fd(const char *file, t_data *data)
{
        int     fd;
        char    *line;

        fd = open(file, O_RDONLY);

//	while (line[0] != 'C')
//		get_next_line(fd, &line);
	ft_get_lines(data, fd, line);
	ft_get_map(data, fd, line);
}

void	ft_get_lines(t_data *data, int fd, char *line)
{
	int	i;

	i = 0;
	get_next_line(fd, &line);
	ft_check_line(data, line);
	while (i < 7)
	{
		while (line[0] != 'C')
		{
			get_next_line(fd, &line);
			ft_check_line(data, line);
		}
		i++;
	}
}

void	ft_check_line(t_data *data, char *line)
{
	if (line[0] == 'R')
		data->descriptor.resolution = line;
	else if (line[0] == 'N' && line[1] == 'O')
		data->descriptor.no = line;
	else if (line[0] == 'S' && line[1] == 'O')
		data->descriptor.so = line;
	else if (line[0] == 'W' && line[1] == 'E')
		data->descriptor.we = line;
	else if (line[0] == 'E' && line[1] == 'A')
		data->descriptor.ea = line;
	else if (line[0] == 'S')
		data->descriptor.sprite = line;
	else if (line[0] == 'F')
		data->descriptor.f = line;
	else if (line[0] == 'C')
		data->descriptor.c = line;
	printf("%s\n", line);
}


