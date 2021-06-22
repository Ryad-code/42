/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:40:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/22 12:33:39 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fract1(t_data *data, t_img *buff)
{
	int			i;
	int			j;
	int			max;

	i = 0;
	j = 0;
	max = data->it_max;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			ft_fract1_3(i, j, data);
			ft_fract1_2(data);
			if (data->it_max < 70)
				ft_my_pixel_put(buff, j, i, data->it_max * 3 * 0x010203);
			data->it_max = max;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_fract1_2(t_data *data)
{
	double	tmp;

	while (data->it_max < 70 && ft_len(data->z) < 2)
	{
		tmp = data->z.nr;
		data->z.nr = (data->z.nr * data->z.nr) - (data->z.ni * data->z.ni)
			+ data->c.nr;
		data->z.ni = 2 * data->z.ni * tmp + data->c.ni;
		data->it_max++;
	}
}

void	ft_fract1_3(int	i, int j, t_data *data)
{
	data->z.nr = (data->tab[j][i]).nr;
	data->z.ni = (data->tab[j][i]).ni;
	data->c.nr = data->j_arg.nr;
	data->c.ni = data->j_arg.ni;
}
