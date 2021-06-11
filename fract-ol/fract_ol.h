#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 400
# define HEIGHT 400

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
	t_mlx	mlx;
	t_img	buff01;
	t_img	buff02;
	t_complex	tab[WIDTH][HEIGHT];
}		t_data;

void	ft_my_pixel_put(t_img *buff, int x, int y, int color);
int     ft_next_frame(int keycode, t_data *data);
void	ft_add(t_complex *a, t_complex *b);
float	ft_len(t_complex a);
void	ft_init_tab(t_data *data);

#endif
