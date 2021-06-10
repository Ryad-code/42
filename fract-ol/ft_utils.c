#include "fract_ol.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
	char    *dst;

	dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
	*(unsigned int*)dst = color;
}

int     ft_next_frame(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
}

int	ft_test(int x, int y)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 50)
	{
		res = (x *x) + y;
		if (res > 2 || res < -2)
			return (i);
		i++;
	}
	return (i);
}
