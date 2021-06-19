#include "fract_ol.h"

int	ft_next_frame(int button, int x, int y, t_data *data)
{
	if (data->cpt % 2 != 0)
	{
		data->buff02.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
		data->buff02.addr = mlx_get_data_addr(data->buff02.img,
		&data->buff02.bpp, &data->buff02.l_len, &data->buff02.endian);
		ft_mouse_hook(button, x, y, data, &data->buff02);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else
	{
		data->buff01.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
		data->buff01.addr = mlx_get_data_addr(data->buff01.img, &data->buff01.bpp,
		&data->buff01.l_len, &data->buff01.endian);
		ft_mouse_hook(button, x, y, data, &data->buff01);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff01.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
}

int	ft_mouse_hook(int button, int x, int y, t_data *data, t_img *buff)
{
	x = 200 + (x / 3);
	y = 200 + (y / 3);
	if (button == 4)
	{
		data->zoom = 0.909091;
		ft_set_tab(data, x, y);
		ft_set_fract(data, buff);
		data->it_max -= 3;
	}
	else if (button == 5)
	{
		data->zoom = 1.1;
		ft_set_tab(data, x, y);
		ft_set_fract(data, buff);
		if (data->it_max <= 47)
			data->it_max += 3;
	}
	ft_set_fract(data, buff);
}
