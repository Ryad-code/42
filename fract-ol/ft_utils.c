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

void	ft_add(t_complex *a, t_complex *b)
{
	a->nr += b->nr;
	a->ni += b->ni;
}

void	ft_mult(t_complex *a, t_complex *b)
{
	t_complex	tmp;
	tmp.nr  = a->nr;
	tmp.ni = a->ni;
	a->nr =  (a->nr * a->ni) - (b->nr * b->ni);
	a->ni = (tmp.nr * b->ni) + (tmp.ni * b->nr);
}

float	ft_len(t_complex a)
{
	return (sqrt(a.nr * a.nr + a.ni * a.ni));
}

void	ft_init_tab(t_data *data)
{
	int		i;
	int		j;
	double 		start_r;
	double		start_i;
	t_complex	tmp;

	i = 0;
	j = 0;
	start_r = -2.00;
	start_i = 2.00;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			tmp.nr = start_r;
			tmp.ni = start_i;
			data->tab[j][i] = tmp;
			start_r += 0.01;
			j++;
		}
		j = 0;
		start_r = -2.00;
		start_i -= 0.01;
		i++;
	}
}

void	ft_display_tab(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			printf("%f + %f\n", (data.tab[j][i]).nr, (data.tab[j][i]).ni);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_test(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			if (ft_len(data.tab[j][i]) < 2)
				ft_my_pixel_put(&data.buff01, j, i, 0x0FF0000);
			j++;
		}
		j = 0;
		i++;
	}
}