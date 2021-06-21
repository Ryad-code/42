/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:39:50 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/21 13:50:21 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <complex.h>

# define WIDTH 600
# define HEIGHT 600

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}		t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int	l_len;
	int	bpp;
	int	endian;
}		t_img;

typedef struct	s_complex
{
	float	nr;
	float	ni;
}		t_complex;

typedef struct s_data
{
	t_mlx		mlx;
	t_img		buff01;
	t_img		buff02;
	t_complex	tab[WIDTH][HEIGHT];
	double		precision;
	double		scale;
	float           zoom;
	int		cpt;
	int		it_max;
	char		arg;
	char		*j_r;
	char		*j_i;
	t_complex	j_arg;
}		t_data;

void	ft_my_pixel_put(t_img *buff, int x, int y, int color);
int     ft_key_hook(int keycode, t_data *data);
int	ft_mouse_hook(int button, int x, int y, t_data *data, t_img *buff);
float	ft_len(t_complex a);
int     ft_isdigit(int c);
int	ft_check_arg(char *arg);
int	ft_args(int ac, char **av, t_data *data);
int     ft_args2(int ac, char **av, t_data *data);
void	ft_init_tab(t_data *data);
void    ft_set_tab(t_data *data, int x, int y);
void	ft_set_fract(t_data *data, t_img *buff);
void	ft_fract(t_data *data, t_img *buff);
void    ft_fract1(t_data *data, t_img *buff);
void    ft_fract1_2(int max, t_complex *z, t_complex *c, t_data *data);
int	ft_next_frame(int button, int x, int y, t_data *data);

int	ft_check(char *a);
double	ft_set_nb(char  *a);
int     ft_atoi(char *str);

#endif
