#include "../cub3d.h"

void	ft_keycode(int keycode, t_data *data, t_img *buff)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	else if (keycode == 65361 || keycode == 65362 || keycode == 65363 || keycode == 65364)
		ft_move_player(keycode, data, buff);
	else if (keycode == 97 || keycode == 122)
		ft_turn_player(keycode, data);
//	printf("grid  = %d:%d\n", data->grid[(int)nearbyint(data->player.x)][(int)nearbyint(data->player.y)], data->grid[(int)nearbyint(data->player.x + 1)][(int)nearbyint(data->player.y + 1)]);
//	printf("pos   = %lf | %lf\n", data->player.x, data->player.y);
//	printf("angle = %lf\n----------\n", data->player.angle);
//	printf("delta = %lf\n----------\n", data->player.delta);
}

void	ft_move_player(int keycode, t_data *data, t_img *buff)
{
	if (keycode == 65362)
		ft_move(data, buff);
	if (keycode == 65364)
		ft_move_back(data, buff);
	if (keycode == 65361)
		ft_move_left(data, buff);
	if (keycode == 65363)
		ft_move_right(data, buff);
}

void	ft_turn_player(int keycode, t_data *data)
{
	if ( keycode == 97)
	{
		data->player.angle -= 2;
		if (data->player.angle < -45)
			data->player.angle = 315 - (data->player.angle + 45);
	}
	else if (keycode == 122)
	{
		data->player.angle += 2;
		if (data->player.angle > 315)
			data->player.angle = -45 + (data->player.angle - 315);
	}
}

void	ft_move(t_data *data, t_img *buff)
{
	ft_get_delta(data);
	if (data->player.angle >= -45 && data->player.angle < 45 && data->grid[(int)nearbyint(data->player.x + 2)][(int)nearbyint(data->player.y + (2 * data->player.delta))] == 0)
	{
		data->player.x++;
		data->player.y += data->player.delta;
	}
	else if (data->player.angle >= 45 && data->player.angle < 135 && data->grid[(int)nearbyint(data->player.x + (2 * data->player.delta))][(int)nearbyint(data->player.y + 2)] == 0)
	{
		data->player.y++;
		data->player.x += data->player.delta;
	}
	else if (data->player.angle >= 135 && data->player.angle < 225 && data->grid[(int)nearbyint(data->player.x - 2)][(int)nearbyint(data->player.y - (2 * data->player.delta))] == 0)
	{
		data->player.x--;
		data->player.y -= data->player.delta;
	}
	else if (data->player.angle >= 225 && data->player.angle <= 315 && data->grid[(int)nearbyint(data->player.x - (2 * data->player.delta))][(int)nearbyint(data->player.y - 2)] == 0)
	{
		data->player.y--;
		data->player.x -= data->player.delta;
	}
}

void	ft_move_back(t_data *data, t_img *buff)
{
	if (data->player.angle >= 135)
	{
		data->player.angle -= 180;
		ft_move(data, buff);
		data->player.angle += 180;
	}
	else if (data->player.angle <= 135)
	{
		data->player.angle += 180;
		ft_move(data, buff);
		data->player.angle -= 180;
	}
}

void	ft_move_left(t_data *data, t_img *buff)
{
	if (data->player.angle <= 45)
	{
		data->player.angle += 270;
		ft_move(data, buff);
		data->player.angle -= 270;
	}
	else if (data->player.angle >= 45)
	{
		data->player.angle -= 90;
		ft_move(data, buff);
		data->player.angle += 90;
	}
}

void	ft_move_right(t_data *data, t_img *buff)
{
	if (data->player.angle >= 225)
	{
		data->player.angle -= 270;
		ft_move(data, buff);
		data->player.angle += 270;
	}
	else if (data->player.angle <= 225)
	{
		data->player.angle += 90;
		ft_move(data, buff);
		data->player.angle -= 90;
	}
}
