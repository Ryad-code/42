#include "../cub3d.h"

void	ft_ray(t_data *data, t_img *buff)
{
	double	tmp;
	int	i;
	int	j;

	j = 0;

	data->player.angle -= 30;
	while (j < S_WIDTH)
	{
		tmp = (PI / 180) * data->player.angle;
		i = 0;

		while (data->map.grid[(int)nearbyint(data->player.y + (sin(tmp) * i)) / B_SIZE]
		[(int)nearbyint(data->player.x + (cos(tmp) * i)) / B_SIZE] != 1)
		{
			ft_my_pixel_put(buff, (int)nearbyint(data->player.x + (cos(tmp) * i)),
			(int)nearbyint(data->player.y + (sin(tmp) * i)), 0x00FF0000);
			i++;
		}
		data->player.angle += (60.00000 / S_WIDTH);
		j++;
	}
	data->player.angle -= 30;
}
