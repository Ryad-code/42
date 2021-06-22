/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:40:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/22 12:33:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_fract(t_data *data, t_img *buff)
{
	if (data->arg == 'M')
		ft_fract(data, buff);
	else if (data->arg == 'J')
		ft_fract1(data, buff);
}

void	ft_fract(t_data *data, t_img *buff)
{
	int			i;
	int			j;
	int			max;
	double		tmp;

	i = 0;
	j = 0;
	max = data->it_max;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			data->z.nr = 0.000000;
			data->z.ni = 0.000000;
			ft_fract_2(i, j, data);
			if (data->it_max < 70)
				ft_my_pixel_put(buff, j, i,
					data->it_max * 3 * 3 * 3 * 0x010203);
			data->it_max = max;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_fract_2(int i, int j, t_data *data)
{
	double	tmp;

	while (data->it_max < 70 && ft_len(data->z) < 2)
	{
		tmp = data->z.nr;
		data->z.nr = (data->z.nr * data->z.nr)
			- (data->z.ni * data->z.ni) + (data->tab[j][i]).nr;
		data->z.ni = 2 * data->z.ni * tmp + (data->tab[j][i]).ni;
		data->it_max++;
	}
}
