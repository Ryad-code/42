/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:40:51 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/22 12:03:53 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_frame(t_data *data, t_img *buff)
{
	buff->img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	buff->addr = mlx_get_data_addr(buff->img,
			 &buff->bpp, &buff->l_len, &buff->endian);
}

int	ft_next_frame(int button, int x, int y, t_data *data)
{
	t_input	input;

	input = ft_input(button, x, y);
	if (data->cpt % 2 != 0)
	{
		ft_frame(data, &data->buff02);
		ft_mouse_hook(input, data, &data->buff02);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff01.img);
	}
	else
	{
		ft_frame(data, &data->buff01);
		ft_mouse_hook(input, data, &data->buff01);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->buff01.img, 0, 0);
		mlx_destroy_image(data->mlx.mlx, data->buff02.img);
	}
	data->cpt++;
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
}

t_input	ft_input(int button, int x, int y)
{
	t_input	tab;

	tab.button = button;
	tab.x = x;
	tab.y = y;
	return (tab);
}

int	ft_mouse_hook(t_input input, t_data *data, t_img *buff)
{
	input.x = 200 + (input.x / 3);
	input.y = 200 + (input.y / 3);
	if (input.button == 4)
	{
		data->zoom = 0.909091;
		ft_set_tab(data, input.x, input.y);
		ft_set_fract(data, buff);
		data->it_max -= 3;
	}
	else if (input.button == 5)
	{
		data->zoom = 1.1;
		ft_set_tab(data, input.x, input.y);
		ft_set_fract(data, buff);
		if (data->it_max <= 47)
			data->it_max += 3;
	}
	ft_set_fract(data, buff);
}
