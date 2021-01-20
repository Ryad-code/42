#include "../cub3d.h"

void	ft_init_grid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAP_HEIGHT * SIZE)
	{
		while (j < MAP_WIDTH * SIZE)
		{
			data->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_get_map(t_data *data, int fd, char *line)	//Récupération de la map dans data.map
{
	int	i;
	int	j;

	i = 0;
	j = 0;
        while (i < MAP_HEIGHT)
        {
                get_next_line(fd, &line);
                while (j < MAP_WIDTH)
                {
                        data->map[i][j] = line[j] - 48;
                        j++;
                }
                j = 0;
                i++;
        }
}

void    ft_draw_map(t_data *data, t_img *buff)
{
        int i;
        int j;

        i = 0;
        j = 0;
        while (i < MAP_WIDTH)
        {
                while (j < MAP_HEIGHT)
                {
                        if (data->map[i][j] == 1)
                                ft_draw_block(data, buff, j * SIZE, i * SIZE);
                        j++;
                }
                j = 0;
                i++;
        }
}
