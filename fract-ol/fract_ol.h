#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <complex.h>

# define WIDTH 600
# define HEIGHT 600
# define ZOOM 1.1

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
	int		cpt;
	int		it_max;
}		t_data;

void	ft_my_pixel_put(t_img *buff, int x, int y, int color);
int     ft_key_hook(int keycode, t_data *data);
int	ft_mouse_hook(int button, int x, int y, t_data *data, t_img *buff);
float	ft_len(t_complex a);
void	ft_init_tab(t_data *data);
void    ft_set_tab(t_data *data, int x, int y);
void    ft_display_tab(t_data data);
void	ft_fract(t_data *data, t_img *buff);
int	ft_next_frame(int button, int x, int y, t_data *data);

#endif
