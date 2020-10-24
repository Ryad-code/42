#include "cub3d.h"

int     next_img(int keycode, t_data *data)
{
        if (keycode == 65364 && data->img.y < 900)
        {
		data->img.y += 100;
		draw(data);
        }
	else if (keycode == 65363 && data->img.x < 900)
	{
		data->img.x += 100;
		draw(data);
	}
	else if (keycode == 65361 && data->img.x > 0)
	{
		data->img.x -= 100;
		draw(data);
	}
	else if (keycode == 65362 && data->img.y > 0)
	{
		data->img.y -= 100;
		draw(data);
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

void	draw(t_data *data)
{
	draw_square(&data->img);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
}
