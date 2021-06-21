/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:40:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/21 13:54:24 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
	t_complex	z;
	double		tmp;

	i = 0;
	j = 0;
	max = data->it_max;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			z.nr = 0.000000;
			z.ni = 0.000000;
			while (data->it_max < 70 && ft_len(z) < 2)
			{
				tmp = z.nr;
				z.nr = (z.nr * z.nr) - (z.ni * z.ni) + (data->tab[j][i]).nr;
				z.ni = 2 * z.ni * tmp + (data->tab[j][i]).ni;
				data->it_max++;
			}
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

void	ft_fract1(t_data *data, t_img *buff)
{
	int			i;
	int			j;
	int			max;
	t_complex	z;
	t_complex	c;
	double		tmp;

	i = 0;
	j = 0;
	max = data->it_max;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			z.nr = (data->tab[j][i]).nr;
			z.ni = (data->tab[j][i]).ni;
			c.nr = data->j_arg.nr;
			c.ni = data->j_arg.ni;
			while (data->it_max < 70 && ft_len(z) < 2)
			{
				tmp = z.nr;
				z.nr = (z.nr * z.nr) - (z.ni * z.ni) + c.nr;
				z.ni = 2 * z.ni * tmp + c.ni;
				data->it_max++;
			}
			if (data->it_max < 70)
				ft_my_pixel_put(buff, j, i, data->it_max * 3 * 0x010203);
			data->it_max = max;
			j++;
		}
		j = 0;
		i++;
	}
}
