#include "../cub3d.h"

void	ft_init_buff(t_data *data, t_img *buff)
{
	buff->img = mlx_new_image(data->mlx.mlx, MAP_WIDTH * SIZE, MAP_HEIGHT * SIZE);
	buff->addr = mlx_get_data_addr(buff->img, &buff->bpp, &buff->l_len, &buff->endian);
}

void	ft_switch_data(t_img *from_buff, t_img *to_buff)
{
	to_buff->player.x = from_buff->player.x;
	to_buff->player.y = from_buff->player.y;
	to_buff->player.angle = from_buff->player.angle;
	to_buff->player.delta = from_buff->player.delta;
}

int	ft_next_frame(int keycode, t_data *data)
{
	if (data->cpt % 2 != 0)
	{
		ft_init_buff(data, &data->buff02);
		ft_switch_data(&data->buff01, &data->buff02);
		ft_draw_map(data, &data->buff02);

		ft_keycode(keycode, data, &data->buff02);
		ft_raycast(data, &data->buff02);

		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else if (data->cpt % 2 == 0)
	{
		ft_init_buff(data, &data->buff01);
		ft_switch_data(&data->buff02, &data->buff01);
		ft_draw_map(data, &data->buff01);

		ft_keycode(keycode, data, &data->buff01);
		ft_raycast(data, &data->buff01);

		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff01.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
}
