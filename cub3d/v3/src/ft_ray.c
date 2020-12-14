#include "../cub3d.h"

void	ft_get_delta(t_img *buff)
{	
	double	tmp;

	tmp  = (PI / 180) * buff->player.angle;
	if (buff->player.angle >= -45 && buff->player.angle <= 45 || buff->player.angle >= 135 && buff->player.angle <= 225)
		buff->player.delta = (sin(tmp) / cos(tmp));
	else if (buff->player.angle >= 45 && buff->player.angle <= 135 || buff->player.angle >= 225 && buff->player.angle <= 315)
		buff->player.delta = (cos(tmp) / sin(tmp));
}

void	ft_ray_right(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	i = 0;
	tmp = buff->player.delta;
	while (data->grid[(int)nearbyint(buff->player.x + i)][(int)nearbyint(buff->player.y + tmp)] == 0)
	{
		ft_my_pixel_put(buff, (int)nearbyint(buff->player.x + i), (int)nearbyint(buff->player.y + tmp), 0x00FF0000);
		i++;
		tmp += buff->player.delta;
	}
}

void    ft_ray_left(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	tmp = buff->player.delta;
	i = 0;
	while (data->grid[(int)nearbyint(buff->player.x - i)][(int)nearbyint(buff->player.y - tmp)] == 0)
	{
		ft_my_pixel_put(buff, (int)nearbyint(buff->player.x - i), (int)nearbyint(buff->player.y - tmp), 0x00FF0000);
		i++;
		tmp += buff->player.delta;
	}
}

void	ft_ray_up(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	tmp = buff->player.delta;
	i = 0;
	while (data->grid[(int)nearbyint(buff->player.x - tmp)][(int)nearbyint(buff->player.y - i)] == 0)
	{
		ft_my_pixel_put(buff, (int)nearbyint(buff->player.x - tmp), (int)nearbyint(buff->player.y - i), 0x00FF0000);
		i++;
		tmp += buff->player.delta;
	}
}

void	ft_ray_down(t_data *data, t_img *buff)
{
	int	i;
	double	tmp;

	tmp = buff->player.delta;
	i = 0;
	while(data->grid[(int)nearbyint(buff->player.x + tmp)][(int)nearbyint(buff->player.y + i)] == 0)
	{
		ft_my_pixel_put(buff, (int)nearbyint(buff->player.x + tmp), (int)nearbyint(buff->player.y + i), 0x00FF0000);
		i++;
		tmp += buff->player.delta;
	}
}

void	ft_vision(t_data *data, t_img *buff)
{
	int	i;

	i = 0;
	while (i < 60)
	{
		ft_get_delta(buff);
		if (buff->player.angle >= -45 && buff->player.angle <= 45)
			ft_ray_right(data, buff);
		else if (buff->player.angle >= 45 && buff->player.angle <= 135)
			ft_ray_down(data, buff);
		else if (buff->player.angle >= 135 && buff->player.angle <= 225)
			ft_ray_left(data, buff);
		else if	(buff->player.angle >= 225 && buff->player.angle <= 315)
			ft_ray_up(data, buff);
		buff->player.angle++;
		i++;
	}
	buff->player.angle -= 60;
}
