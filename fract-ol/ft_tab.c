#include "fract_ol.h"

void	ft_init_tab(t_data *data)
{
	int		i;
	int		j;
	double		start_r;
	double		start_i;
	t_complex	tmp;

	i = 0;
	j = 0;
	start_r = -3.000000;
	start_i = 3.000000;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			tmp.nr = start_r;
			tmp.ni = start_i;
			data->tab[j][i] = tmp;
			start_r += data->precision;
			j++;
		}
		j = 0;
		start_r = -3.00;
		start_i -= data->precision;
		i++;
	}
}

void	ft_set_tab(t_data *data, int x, int y)
{
	int 	i;
	int	j;
	double          start_r;
	double          start_i;
	double		tmp;

	i = 0;
	j = 0;
	start_r = (data->tab[x][y]).nr - ((data->scale * ZOOM) / 2);
	start_i = (data->tab[x][y]).ni + ((data->scale * ZOOM) / 2);
	tmp = start_r;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			(data->tab[j][i]).nr = start_r;
			(data->tab[j][i]).ni = start_i;
			start_r += (data->scale * ZOOM) / WIDTH;
			j++;	
		}
		start_r = tmp;
		start_i -= (data->scale * ZOOM) / WIDTH;
		j = 0;
		i++;
	}
	data->scale = data->scale * ZOOM;
}



void    ft_display_tab(t_data data)
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
		j= 0;
		i++;
	}
}
