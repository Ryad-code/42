#include "../cub3d.h"

void	ft_check_fd(t_data *data, int fd)
{
	int	i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) > data->map.g_width)
			data->map.g_width = ft_strlen(line);
		i++;
		free(line);
	}
	data->map.g_height = i;
	free(line);
	printf("w=%d\n", data->map.g_width);
	printf("h=%d\n", data->map.g_height);
}

void	ft_mem_grid(t_data *data)
{
	int	i;

	i = 0;
	data->map.grid = (int **)malloc(sizeof(int *) * data->map.g_height + 1);
	while (i < data->map.g_height)
	{
		data->map.grid[i] = (int *)malloc(sizeof(int) * data->map.g_width + 1);
		i++;
	}
}

void	ft_init_grid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.g_height)
	{
		while (j < data->map.g_width)
		{
			data->map.grid[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_get_grid(t_data *data, int fd)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	fd = open("maps/map01.txt", O_RDONLY);
	while (i < data->map.g_height)
	{
		get_next_line(fd, &line);
		while (j < ft_strlen(line))
		{
			data->map.grid[i][j] = line[j] - 48;
			j++;
		}
		free(line);
		i++;
		j = 0;
	}
}


void 	ft_display_grid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.g_height)
	{
		while (j < data->map.g_width)
		{
			printf("%d.", data->map.grid[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}
