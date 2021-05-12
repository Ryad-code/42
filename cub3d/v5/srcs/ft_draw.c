#include "../cub3d.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
        char    *dst;

        dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
        *(unsigned int*)dst = color;
}

void	ft_draw_line(t_data *data, t_img *buff, int x, int y)
{
	int	i;

	i = 0;
	while (i < B_SIZE)
	{
		ft_my_pixel_put(buff, x + i, y, 0x0000FF);
		i++;
	}
}

void    ft_draw_block(t_data *data, t_img *buff, int x, int y)
{
	int	i;

	i = 0;
	while (i < B_SIZE)
	{
		ft_draw_line(data, buff, x, y + i);
		i++;
	}
}

void	ft_draw_map(t_data *data, t_img *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.g_height)
	{
		while (j < data->map.g_width)
		{
			if (data->map.grid[i][j] == 1)
				ft_draw_block(data, buff, j * B_SIZE, i * B_SIZE);
			else if (data->map.grid[i][j] == 2 && data->cpt == 1)
			{
				data->player.x = j * B_SIZE;
				data->player.y = i * B_SIZE;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

