#include "../cub3d.h"

void	ft_get_delta(t_data *data)
{	
	double	tmp;

	tmp  = (PI / 180) * data->player.angle;
	if (data->player.angle >= -45 && data->player.angle <= 45 || data->player.angle >= 135 && data->player.angle <= 225)
		data->player.delta = (sin(tmp) / cos(tmp));
	else if (data->player.angle >= 45 && data->player.angle <= 135 || data->player.angle >= 225 && data->player.angle <= 315)
		data->player.delta = (cos(tmp) / sin(tmp));
}

void	ft_ray_right(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	i = 0;
	tmp = data->player.delta;
	while (data->grid[(int)nearbyint(data->player.x + i)][(int)nearbyint(data->player.y + tmp)] == 0)
	{
//		ft_my_pixel_put(buff, (int)nearbyint(data->player.x + i), (int)nearbyint(data->player.y + tmp), 0x00FF0000);
		i++;
		tmp += data->player.delta;
	}
	data->player.r_len = sqrt((i * i) + (tmp * tmp));
}

void    ft_ray_left(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	tmp = data->player.delta;
	i = 0;
	while (data->grid[(int)nearbyint(data->player.x - i)][(int)nearbyint(data->player.y - tmp)] == 0)
	{
//		ft_my_pixel_put(buff, (int)nearbyint(data->player.x - i), (int)nearbyint(data->player.y - tmp), 0x00FF0000);
		i++;
		tmp += data->player.delta;
	}
	data->player.r_len = sqrt((i * i) + (tmp * tmp));
}

void	ft_ray_up(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	tmp = data->player.delta;
	i = 0;
	while (data->grid[(int)nearbyint(data->player.x - tmp)][(int)nearbyint(data->player.y - i)] == 0)
	{
//		ft_my_pixel_put(buff, (int)nearbyint(data->player.x - tmp), (int)nearbyint(data->player.y - i), 0x00FF0000);
		i++;
		tmp += data->player.delta;
	}
	data->player.r_len = sqrt((i * i) + (tmp * tmp));
}

void	ft_ray_down(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	tmp = data->player.delta;
	i = 0;
	while(data->grid[(int)nearbyint(data->player.x + tmp)][(int)nearbyint(data->player.y + i)] == 0)
	{
//		ft_my_pixel_put(buff, (int)nearbyint(data->player.x + tmp), (int)nearbyint(data->player.y + i), 0x00FF0000);
		i++;
		tmp += data->player.delta;
	}
	data->player.r_len = sqrt((i * i) + (tmp * tmp));
}

void	ft_ray(t_data *data, t_img *buff)
{
	ft_get_delta(data);
	if (data->player.angle >= -45 && data->player.angle <= 45)
		ft_ray_right(data, buff);
	else if (data->player.angle >= 45 && data->player.angle <= 135)
		ft_ray_down(data, buff);
	else if (data->player.angle >= 135 && data->player.angle <= 225)
		ft_ray_left(data, buff);
	else if	(data->player.angle >= 225 && data->player.angle <= 315)	
		ft_ray_up(data, buff);
		
}

void	ft_raycast(t_data *data, t_img *buff)
{
	int	i;
	double	min;
	double	max;
	double	tmp;

	i = 0;
	tmp = data->player.angle;
	if (tmp < -15)
	{
		min = tmp + 330;
		max = tmp + 30;
	}
	else if (tmp > 285)
	{
		min = tmp - 30;
		max = tmp - 330;
	}
	else
	{
		min = tmp - 30;
		max = tmp + 30;
	}
	data->player.angle = min;
	while (i < SCREEN_WIDTH)
	{
		ft_ray(data, buff);
		ft_draw_screen(data, buff, i, SCREEN_HEIGHT / 2);
		data->player.angle += 0.15;
		if (data->player.angle > 315)
			data->player.angle = -45 + (data->player.angle - 315);
		i++;
	}
	data->player.angle = tmp;
}
