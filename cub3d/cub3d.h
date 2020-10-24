#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	l_len;
	int	endian;
	int	x;
	int	y;
	int	color;
}		t_img;

typedef struct	s_data
{
	t_mlx	mlx;
	t_img	img;
}		t_data;

void    my_pixel_put(t_img *img, int x, int y, int color);
void    draw_line(t_img *img);
void    draw_square(t_img *img);
void	draw(t_data *data);
int	next_img(int keycode, t_data *data);

