#include "cub3d.h"

int     next_img(int keycode, t_data *data)
{
        if (keycode == 65364 && data->buff.y < 900)
		draw_down(data);
	else if (keycode == 65363 && data->buff.x < 900)
		draw_right(data);
	else if (keycode == 65361 && data->buff.x > 0)
		draw_left(data);
	else if (keycode == 65362 && data->buff.y > 0)
		draw_up(data);
        else if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx.ptr, data->mlx.win);
                exit(0);
        }
        return (0);
}

void	draw1(t_data *data)
{
	draw_square(&data->buff);
	draw_block(&data->buff);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->buff.img, 0, 0);
	mlx_destroy_image(data->mlx.ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx.ptr, 1000, 1000);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.l_len, &data->img.endian);
	data->img.x = data->buff.x;
	data->img.y = data->buff.y;
}

void	draw2(t_data *data)
{
	draw_square(&data->img);
	draw_block(&data->img);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx.ptr, data->buff.img);
	data->buff.img = mlx_new_image(data->mlx.ptr, 1000, 1000);
	data->buff.addr = mlx_get_data_addr(data->buff.img, &data->buff.bpp, &data->buff.l_len, &data->buff.endian);
	data->buff.x = data->img.x;
        data->buff.y = data->img.y;
}

void	draw_down(t_data *data)
{
	if (data->cpt % 2 ==! 0)
	{
		data->buff.y += 10;
		draw1(data);
	}
	else
	{
		data->img.y += 10;
		draw2(data);
	}
	data->cpt++;
}

void    draw_up(t_data *data)
{
        if (data->cpt % 2 ==! 0)
        {
                data->buff.y -= 10;
                draw1(data);
        }
        else
        {
                data->img.y -= 10;
                draw2(data);
	}
        data->cpt++;
}

void    draw_right(t_data *data)
{
        if (data->cpt % 2 ==! 0)
        {
                data->buff.x += 10;
                draw1(data);
        }
        else
        {
                data->img.x += 10;
                draw2(data);
	}
        data->cpt++;
}

void    draw_left(t_data *data)
{
        if (data->cpt % 2 ==! 0)
        {
                data->buff.x -= 10;
                draw1(data);
        }
        else
        {
                data->img.x -= 10;
                draw2(data);
	}
        data->cpt++;
}




