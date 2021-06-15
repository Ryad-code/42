#include "fract_ol.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
	char    *dst;

	dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
	*(unsigned int*)dst = color;
}

int     ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
}

int	ft_mouse_hook(int button, int x, int y, t_data *data, t_img *buff)
{
	if (button == 4)
	{
		ft_set_tab(data, x, y);
		ft_test(*data, buff);
	}
	printf("button = %d\n", button);
	printf("pos = %d, %d\n", x, y);
}

float	ft_len(t_complex a)
{
	return (sqrt(a.nr * a.nr + a.ni * a.ni));
}

void	ft_test(t_data data, t_img *buff)
{
	int	i;
	int	j;
	int	max;
	t_complex	z;
	double	tmp;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			z.nr = 0.000000;
			z.ni = 0.000000;
			while (max < 20 && ft_len(z) < 2)
			{
				tmp = z.nr;
				z.nr = (z.nr * z.nr) - (z.ni * z.ni) + (data.tab[j][i]).nr;
				z.ni = 2 * z.ni * tmp + (data.tab[j][i]).ni;
				max++;
			}
			if (max < 20)
				ft_my_pixel_put(buff, j, i, max * 10 * 0x010203);
			max = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
