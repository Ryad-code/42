#include "../cub3d.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
        char    *dst;

        dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
        *(unsigned int*)dst = color;

}

void    ft_draw_line(t_data *data, t_img *buff, int x, int y)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		ft_my_pixel_put(buff, x + i, y, BLOCK_COLOR);
		if (data->cpt == 1)
			data->grid[x + i][y] = 1;
		i++;
        }
}

void	ft_draw_block(t_data *data, t_img *buff, int x, int y)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		ft_draw_line(data, buff, x, y + i);
		i++;
	}
}

void	ft_draw_f_line(t_data *data, t_img *buff, int x, int y)
{
	int	i;
	
	i = 0;
	while (i < 200)
	{
		ft_my_pixel_put(buff, x , i , SKY_COLOR + 1);
		i++;
	}
	i = 0;
	if (buff->player.r_len < 25)
	{
		while (i < 400)
		{
			ft_my_pixel_put(buff, x , 0 + i , BLOCK_COLOR);
			i++;
		}
		i = 0;
	}
	else 
	{
		while (i < (int)nearbyint((1 / buff->player.r_len) * 10000) / 2)
		{
			ft_my_pixel_put(buff, x , y + i , BLOCK_COLOR);
			ft_my_pixel_put(buff, x , y - i , BLOCK_COLOR);
			i++;
		}
	}
}
