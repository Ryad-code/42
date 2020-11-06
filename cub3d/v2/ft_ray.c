#include "cub3d.h"

void	ft_get_dir(t_img *buff)
{
	double tmp;

	tmp = (PI / 180) * buff->player.angle;
	buff->player.dir_x = cos(tmp); 
	buff->player.dir_y = sin(tmp);
}

void	ft_ray_right(t_img *buff)
{
	double delta_y;

	delta_y = buff->player.dir_y / buff->player.dir_x;
	buff->player.dir_x = 0;
	buff->player.dir_y = delta_y;
	if (buff->player.angle <= 45 && buff->player.angle >= -45)
		while (buff->tab[(int)(buff->player.x + buff->player.dir_x)]
		[buff->player.y + (int)nearbyint(buff->player.dir_y)] == 0)
		{
			buff->player.dir_y += delta_y;
			buff->player.dir_x++;
//			ft_my_pixel_put(buff, buff->player.x + buff->player.dir_x, buff->player.y + (int)nearbyint(buff->player.dir_y), 0x00FF0000);
		}
	buff->r_len = sqrt((buff->player.dir_x * buff->player.dir_x) + (buff->player.dir_y * buff->player.dir_y));
}

void	ft_ray_left(t_img *buff)
{
	double delta_y;

	delta_y = buff->player.dir_y / buff->player.dir_x;
	delta_y = delta_y * -1;
	buff->player.dir_x = 0;
	buff->player.dir_y = delta_y;
	if (buff->player.angle >= 135 && buff->player.angle <= 180)
		while (buff->tab[(int)(buff->player.x - buff->player.dir_x)]
		[buff->player.y + (int)nearbyint(buff->player.dir_y)] == 0)
		{
			buff->player.dir_y += delta_y;
			buff->player.dir_x++;
//			ft_my_pixel_put(buff, buff->player.x - buff->player.dir_x, buff->player.y + (int)nearbyint(buff->player.dir_y), 0x00FF0000);
		}
	else if (buff->player.angle >= 180 && buff->player.angle <= 225)
		while (buff->tab[(int)(buff->player.x - buff->player.dir_x)]
		[buff->player.y + (int)nearbyint(buff->player.dir_y)] == 0)
		{
			buff->player.dir_y += delta_y;
			buff->player.dir_x++;
//			ft_my_pixel_put(buff, buff->player.x - buff->player.dir_x, buff->player.y + (int)nearbyint(buff->player.dir_y), 0x00FF0000);
		}
	buff->r_len = sqrt((buff->player.dir_x * buff->player.dir_x) + (buff->player.dir_y * buff->player.dir_y));
}

void	ft_ray_down(t_img *buff)
{
	double delta_x;

	delta_x = buff->player.dir_x / buff->player.dir_y;
	buff->player.dir_y = 0;
	buff->player.dir_x = delta_x;
	if (buff->player.angle <= 90 && buff->player.angle >= 45)
		while (buff->tab[buff->player.x + (int)nearbyint(buff->player.dir_x)]
		[(int)(buff->player.y + buff->player.dir_y)] == 0)
		{
			buff->player.dir_x += delta_x;
			buff->player.dir_y++;
//			ft_my_pixel_put(buff, buff->player.x + (int)nearbyint(buff->player.dir_x), buff->player.y + buff->player.dir_y, 0x00FF0000);
		}
	else if (buff->player.angle <= 135 && buff->player.angle >= 90)
		while (buff->tab[buff->player.x + (int)nearbyint(buff->player.dir_x)]
		[(int)(buff->player.y + buff->player.dir_y)] == 0)
		{
			buff->player.dir_x += delta_x;
			buff->player.dir_y++;
//			ft_my_pixel_put(buff, buff->player.x + (int)nearbyint(buff->player.dir_x), buff->player.y + buff->player.dir_y, 0x00FF0000);
		}
	buff->r_len = sqrt((buff->player.dir_x * buff->player.dir_x) + (buff->player.dir_y * buff->player.dir_y));
}

void    ft_ray_up(t_img *buff)
{
	double delta_x;

	delta_x = buff->player.dir_x / buff->player.dir_y;
	buff->player.dir_y = 0;
	buff->player.dir_x = delta_x;
	if (buff->player.angle <= 270 && buff->player.angle >= 225)
		while (buff->tab[buff->player.x - (int)nearbyint(buff->player.dir_x)]
		[(int)(buff->player.y - buff->player.dir_y)] == 0)
		{
			buff->player.dir_x += delta_x;
			buff->player.dir_y++;
//			ft_my_pixel_put(buff, buff->player.x - (int)nearbyint(buff->player.dir_x), buff->player.y - buff->player.dir_y, 0x00FF0000);
			
		}
	else if (buff->player.angle <= 315 && buff->player.angle >= 270)
	{
		delta_x = delta_x * -1;
		while (buff->tab[buff->player.x + (int)nearbyint(buff->player.dir_x)]
		[(int)(buff->player.y - buff->player.dir_y)] == 0)
		{
			buff->player.dir_x += delta_x;
			buff->player.dir_y++;
//			ft_my_pixel_put(buff, buff->player.x + (int)nearbyint(buff->player.dir_x), buff->player.y - buff->player.dir_y, 0x00FF0000);
		}
	}
	buff->r_len = sqrt((buff->player.dir_x * buff->player.dir_x) + (buff->player.dir_y * buff->player.dir_y));
}

void	ft_vision(t_img *buff)
{
	double	delta;
	int i;

	i = 0;
	delta = 0.706748;
	if (buff->player.angle < -15)
		buff->player.angle += 330;
	else
		buff->player.angle -= 30;
	while (i < 576)
	{
		ft_get_dir(buff);
		if (buff->player.angle <= 45)
			ft_ray_right(buff);
		else if (buff->player.angle <= 135)
			ft_ray_down(buff);
		else if (buff->player.angle <= 225)
			ft_ray_left(buff);
		else if (buff->player.angle <= 315)
			ft_ray_up(buff);
		ft_draw_line2_1(buff, i, 0, (576 / 2) - ((int)nearbyint(buff->r_len * delta) / 2), 0x0ADD8E6);
		ft_draw_line2(buff, i, (576 / 2) - ((int)nearbyint(buff->r_len * delta) / 2), (int)nearbyint(buff->r_len * delta), 0x00FF0000);
		buff->player.angle += 0.104166;
		if (buff->player.angle > 315)
			buff->player.angle = -44;
		i++;
	}
	if (buff->player.angle < -15)
		buff->player.angle += 330;
	else
		buff->player.angle -= 30;
}
