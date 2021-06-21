/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:40:26 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/21 12:40:30 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_init_tab(t_data *data)
{
	int			i;
	int			j;
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
	int			i;
	int			j;
	t_complex	start;
	double		tmp;

	i = 0;
	j = 0;
	start.nr = (data->tab[x][y]).nr - ((data->scale * data->zoom) / 2);
	start.ni = (data->tab[x][y]).ni + ((data->scale * data->zoom) / 2);
	tmp = start.nr;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			(data->tab[j][i]).nr = start.nr;
			(data->tab[j][i]).ni = start.ni;
			start.nr += (data->scale * data->zoom) / WIDTH;
			j++;
		}
		start.nr = tmp;
		start.ni -= (data->scale * data->zoom) / WIDTH;
		j = 0;
		i++;
	}
	data->scale = data->scale * data->zoom;
}
