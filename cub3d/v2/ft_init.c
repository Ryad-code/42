#include "cub3d.h"

void	ft_init_buff(t_img *buff01)
{
	buff01->pos.x = 0;
	buff01->pos.y = 0;
	buff01->pos.color = 0x00FF0000;
}

void	ft_show_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 24)
	{
		while (j < 24)
		{
			printf("%d", data->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	ft_init_map(char *file, t_data *data)
{
	int	i;
	int	j;
	int	fd;
	char	*line;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (i < MAP_WIDTH)
	{
		get_next_line(fd, &line);
		while (j < MAP_HEIGHT)
		{
			data->map[i][j] = line[j] - 48;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_switch_buff(t_img *buff01, t_img *buff02)
{
	buff01->pos.x = buff02->pos.x;
	buff01->pos.y =  buff02->pos.y;
	buff01->pos.color = buff02->pos.color;
}
