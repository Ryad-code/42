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
		ft_turn_player(keycode, buff);
//	printf("pos   = %d:%d\n", (int)nearbyint(buff->player.x), (int)nearbyint(buff->player.y));
	printf("pos   = %lf:%lf\n", buff->player.x, buff->player.y);
	printf("angle = %lf\n", buff->player.angle);
}

void	ft_move_player(int keycode, t_data *data, t_img *buff)
{
	if (keycode == 65362)
		ft_direction(data, buff);
	if (keycode == 65364)
		ft_move_back(data, buff);
	if (keycode == 65361)
		ft_move_left(data, buff);
	if (keycode == 65363)
		ft_move_right(data, buff);
}

void	ft_turn_player(int keycode, t_img *buff)
{
	if ( keycode == 97)
	{
		buff->player.angle -= 2;
		if (buff->player.angle < -45)
			buff->player.angle = 315 - (buff->player.angle + 45);
	}
	else if (keycode == 122)
	{
		buff->player.angle += 2;
		if (buff->player.angle > 315)
			buff->player.angle = -45 + (buff->player.angle - 315);
	}
}

void	ft_direction(t_data *data, t_img *buff)
{
	ft_get_delta(buff);
	if (buff->player.angle >= -45 && buff->player.angle <= 45 && data->grid[(int)nearbyint(buff->player.x + 1)][(int)nearbyint(buff->player.y + buff->player.delta)] == 0)
	{
		buff->player.x++;
		buff->player.y += buff->player.delta;
	}
	else if (buff->player.angle >= 45 && buff->player.angle <= 135 && data->grid[(int)nearbyint(buff->player.y + 1)][(int)nearbyint(buff->player.x + buff->player.delta)] == 0)
	{
		buff->player.y++;
		buff->player.x += buff->player.delta;
	}
	else if (buff->player.angle >= 135 && buff->player.angle <= 225 && data->grid[(int)nearbyint(buff->player.x - 1)][(int)nearbyint(buff->player.y - buff->player.delta)] == 0)
	{
		buff->player.x--;
		buff->player.y -= buff->player.delta;
	}
	else if (buff->player.angle >= -225 && buff->player.angle <= 315 && data->grid[(int)nearbyint(buff->player.y - 1)][(int)nearbyint(buff->player.x - buff->player.delta)] == 0)
	{
		buff->player.y--;
		buff->player.x -= buff->player.delta;
	}
}

void	ft_move_back(t_data *data, t_img *buff)
{
	if (buff->player.angle >= 135)
	{
		buff->player.angle -= 180;
		ft_direction(data, buff);
		buff->player.angle += 180;
	}
	else if (buff->player.angle <= 135)
	{
		buff->player.angle += 180;
		ft_direction(data, buff);
		buff->player.angle -= 180;
	}
}

void	ft_move_left(t_data *data, t_img *buff)
{
	if (buff->player.angle <= 45)
	{
		buff->player.angle += 270;
		ft_direction(data, buff);
		buff->player.angle -= 270;
	}
	else if (buff->player.angle >= 45)
	{
		buff->player.angle -= 90;
		ft_direction(data, buff);
		buff->player.angle += 90;
	}
}

void	ft_move_right(t_data *data, t_img *buff)
{
	if (buff->player.angle >= 225)
	{
		buff->player.angle -= 270;
		ft_direction(data, buff);
		buff->player.angle += 270;
	}
	else if (buff->player.angle <= 225)
	{
		buff->player.angle += 90;
		ft_direction(data, buff);
		buff->player.angle -= 90;
	}
}
