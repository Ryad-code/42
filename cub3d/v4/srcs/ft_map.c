#include "../cub3d.h"

void	ft_get_grid(t_data *data, int fd)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	while (i < G_HEIGHT)
	{
		get_next_line(fd, &line);
		while (j < G_WIDTH)
		{
			data->map.grid[j][i] = line[j] - 48;
			j++;
		}
		free(line);
		j = 0;
		i++;
	}
}

void 	ft_display_grid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < G_HEIGHT)
	{
		while (j < G_WIDTH)
		{
			printf("grid[%d][%d] = %d\n", i, j, data->map.grid[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}
