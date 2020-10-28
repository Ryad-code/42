#include "cub3d.h"

void	ft_quit(int keycode, t_data *data)
{
	if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx.mlx, data->mlx.win);
                exit(0);
        }
}

void	ft_move_up(t_draw *pos)
{
	if (pos->y > 25)
		pos->y -= 15;
}

void    ft_move_down(t_draw *pos)
{
	if (pos->y < 550)
        	pos->y += 5;
}

void    ft_move_right(t_draw *pos)
{
	if (pos->x < 550)
        	pos->x += 5;
}

void    ft_move_left(t_draw *pos)
{
	if (pos->x > 25)
        	pos->x -= 5;
}

void	ft_move(int keycode, t_img *buff)
{
	if (keycode == 65362)
		ft_move_up(&buff->pos);
	else if (keycode == 65364)
		ft_move_down(&buff->pos);
	else if (keycode == 65363)
		ft_move_right(&buff->pos);
	else if (keycode == 65361)
		ft_move_left(&buff->pos);
}

int	ft_next_img(int keycode, t_data *data)
{
	ft_quit(keycode, data);
	if (data->cpt % 2 != 0)
	{
		data->buff02.img = mlx_new_image(data->mlx.mlx, 600, 600);
		data->buff02.addr = mlx_get_data_addr(data->buff02.img, &data->buff02.bpp, &data->buff02.l_len,     &data->buff02.endian);
		ft_draw_map(data->map, &data->buff02);
		ft_switch_buff(&data->buff02, &data->buff01);
		ft_move(keycode, &data->buff02);
		ft_draw_square(&data->buff02);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else if (data->cpt % 2 == 0)
	{
		data->buff01.img = mlx_new_image(data->mlx.mlx, 600, 600);
   		data->buff01.addr = mlx_get_data_addr(data->buff01.img, &data->buff01.bpp, &data->buff01.l_len,     &data->buff01.endian);
		ft_draw_map(data->map, &data->buff01);
		ft_switch_buff(&data->buff01, &data->buff02);
		ft_move(keycode, &data->buff01);
		ft_draw_square(&data->buff01);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff01.img, 0, 0);
                mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
	return (0);
}
