#include "cub3d.h"

int     next_img(int keycode, t_data *data)
{
	static int i = 1;
        if (keycode == 65364 && data->buff.y < 900)
        {
		if (i % 2 != 0)	
		{
			data->buff.y += 100;
			draw1(data);
		}
		else
		{
			data->img.y += 100;
			draw2(data);
		}
		i++;
        }
	else if (keycode == 65363 && data->buff.x < 900)
	{
		if (i % 2 != 0)
		{
			data->buff.x += 100;
			draw1(data);
		}
		else
		{
			data->img.x += 100;
			draw2(data);
		}
		i++;
	}
	else if (keycode == 65361 && data->buff.x > 0)
	{
		if (i % 2 != 0)
		{
			data->buff.x -= 100;
			draw1(data);
		}
		else
		{
			data->img.x -= 100;
			draw2(data);
		}
		i++;
	}
	else if (keycode == 65362 && data->buff.y > 0)
	{
		if (i % 2 != 0)
		{
			data->buff.y -= 100;
			draw1(data);
		}
		else
		{
			data->img.y -= 100;
			draw2(data);
		}
		data->buff.y -= 100;
		draw1(data);
	}
        else if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx.ptr, data->mlx.win);
                exit(0);
        }
        else
                printf("%d\n", keycode);
        return (0);
}

void	draw1(t_data *data)
{
	draw_square(&data->buff);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->buff.img, 0, 0);
	mlx_destroy_image(data->mlx.ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx.ptr, 1000, 1000);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.l_len, &data->img.endian);
	data->img.x = data->buff.x;
	data->img.y = data->buff.y;
	data->img.color = 0x00FF0000;
	printf("draw1\n");
}

void	draw2(t_data *data)
{
	draw_square(&data->img);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx.ptr, data->buff.img);
	data->buff.img = mlx_new_image(data->mlx.ptr, 1000, 1000);
	data->buff.addr = mlx_get_data_addr(data->buff.img, &data->buff.bpp, &data->buff.l_len, &data->buff.endian);
	data->buff.x = data->img.x;
        data->buff.y = data->img.y;
        data->buff.color = 0x000000FF;
	printf("draw2\n");
}
