#include "cub3d.h"

int     next_img(int keycode, t_data *data)
{
	
	ft_switch_img(keycode, data);
        if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx.mlx, data->mlx.win);
                exit(0);
        }
	else
		printf("%d\n", keycode);
}

void	ft_switch_data(t_data *data)
{
	if (data->cpt % 2 != 0)
	{
		data->buff02.player.angle = data->buff01.player.angle;
		data->buff02.player.x = data->buff01.player.x;
		data->buff02.player.y = data->buff01.player.y;
		data->buff02.player.color = data->buff01.player.color;
	}
	else
	{
		data->buff01.player.angle = data->buff02.player.angle;
		data->buff01.player.x = data->buff02.player.x;
		data->buff01.player.y = data->buff02.player.y;
		data->buff01.player.color = data->buff02.player.color;
	}
}

void	ft_move_player(int keycode, t_img *buff)
{
	if (keycode == 65363)
		buff->player.x += 4;
	else if (keycode == 65361)
		buff->player.x -= 4;
	else if (keycode == 65362)
		buff->player.y -= 4;
	else if (keycode == 65364)
		buff->player.y += 4;	
}

void	ft_turn_player(int keycode, t_img *buff)
{
	if (keycode == 97)
		buff->player.angle++;
	else if (keycode == 98)
		buff->player.angle--;
	if (buff->player.angle < -45)
		buff->player.angle = 314;
	else if (buff->player.angle > 315)
		buff->player.angle = -44;
}

void	ft_switch_img(int keycode, t_data *data)
{
	if (data->cpt % 2 != 0)
	{
		ft_switch_data(data);
		ft_init_grid(&data->buff02);
		ft_move_player(keycode, &data->buff02);
		ft_turn_player(keycode, &data->buff02);

		data->buff02.img = mlx_new_image(data->mlx.mlx, 576, 576);
        	data->buff02.addr = mlx_get_data_addr(data->buff02.img, &data->buff02.bpp,
        	&data->buff02.l_len, &data->buff02.endian);

		ft_display_map(&data->buff02);
		ft_draw_p_square(&data->buff02);
		ft_get_dir(&data->buff02);
	      	test(&data->buff02);

		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else
	{
		ft_switch_data(data);
		ft_init_grid(&data->buff01);
		ft_move_player(keycode, &data->buff01);
		ft_turn_player(keycode, &data->buff01);

		data->buff01.img = mlx_new_image(data->mlx.mlx, 576, 576);
		data->buff01.addr = mlx_get_data_addr(data->buff01.img, &data->buff01.bpp,
                &data->buff01.l_len, &data->buff01.endian);

		ft_display_map(&data->buff01);
		ft_draw_p_square(&data->buff01);
		ft_get_dir(&data->buff01);
		test(&data->buff01);

		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff01.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
}
