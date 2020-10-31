#include "cub3d.h"

void	ft_quit(int keycode, t_data *data)
{
	if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx.mlx, data->mlx.win);
                exit(0);
        }
}

void    ft_init_buff(t_img *buff01)
{
        buff01->pos.x = 0;
        buff01->pos.y = 0;
        buff01->pos.color = 0x00FF0000;
}

void	ft_init_p(t_img *buff, int x, int y, int color, double dir_x, double dir_y, double angle)
{
	buff->pos_p.x = x;
	buff->pos_p.y = y;
	buff->pos_p.color = color;
	buff->pos_p.dir_x = dir_x;
	buff->pos_p.dir_y = dir_y;
	buff->pos_p.angle = angle;
}

void    ft_switch_buff(t_img *buff01, t_img *buff02)
{
	buff01->pos.x = buff02->pos.x;		//pos
	buff01->pos.y =  buff02->pos.y;
	buff01->pos.color = buff02->pos.color;

	buff01->pos_p.x = buff02->pos_p.x;	//pos_p
	buff01->pos_p.y = buff02->pos_p.y;
	buff01->pos_p.color = buff02->pos_p.color;
	buff01->pos_p.dir_x = buff02->pos_p.dir_x;
	buff01->pos_p.dir_y = buff02->pos_p.dir_y;
	buff01->pos_p.angle = buff02->pos_p.angle;
}

int	ft_next_img(int keycode, t_data *data)
{
	ft_quit(keycode, data);
	if (data->cpt % 2 != 0)
	{
		data->buff02.img = mlx_new_image(data->mlx.mlx, 576, 576);
		data->buff02.addr = mlx_get_data_addr(data->buff02.img, &data->buff02.bpp,
		&data->buff02.l_len,     &data->buff02.endian);
		ft_draw_map(data->map, &data->buff02);
		ft_switch_buff(&data->buff02, &data->buff01);
		ft_move(keycode, &data->buff02);
		ft_draw_p_square(&data->buff02);
		ft_draw_dir(&data->buff02);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else if (data->cpt % 2 == 0)
	{
		data->buff01.img = mlx_new_image(data->mlx.mlx, 576, 576);
   		data->buff01.addr = mlx_get_data_addr(data->buff01.img, &data->buff01.bpp,
		&data->buff01.l_len,     &data->buff01.endian);
		ft_draw_map(data->map, &data->buff01);
		ft_switch_buff(&data->buff01, &data->buff02);
		ft_move(keycode, &data->buff01);
		ft_draw_p_square(&data->buff01);
		ft_draw_dir(&data->buff01);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->buff01.img, 0, 0);
                mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
	return (0);
}
