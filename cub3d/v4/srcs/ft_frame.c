#include "../cub3d.h"

int     ft_next_frame(int keycode, t_data *data)
{
	if (data->cpt % 2 != 0)
	{
		data->buff02.img = mlx_new_image(data->mlx.mlx, data->width, data->height);
		data->buff02.addr = mlx_get_data_addr(data->buff02.img, &data->buff02.bpp,
		&data->buff02.l_len, &data->buff02.endian);
		ft_keycode(keycode, data, &data->buff02);
		
		ft_my_pixel_put(&data->buff02, (int)nearbyint(data->player.x), (int)nearbyint(data->player.y), 0x00ff0000);		

		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else
	{
		data->buff01.img = mlx_new_image(data->mlx.mlx, data->width, data->height);
		data->buff01.addr = mlx_get_data_addr(data->buff01.img, &data->buff01.bpp,
		&data->buff01.l_len, &data->buff01.endian);
		ft_keycode(keycode, data, &data->buff01);

		ft_my_pixel_put(&data->buff01, (int)nearbyint(data->player.x), (int)nearbyint(data->player.y), 0x00ff0000);

		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff01.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
//	printf("%lf\n", data->player.x);
//	printf("%lf\n\n", data->player.y);
	return (0);
}
