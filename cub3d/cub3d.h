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
	int	x_o;
	int	y_o;
	int	color_o;
}		t_img;

typedef struct	s_data
{
	t_mlx	mlx;
	t_img	img;
	t_img	buff;
	t_img	obstacle;
	int	cpt;
}		t_data;

void    my_pixel_put(t_img *img, int x, int y, int color);
void    draw_line(t_img *img);
void    draw_square(t_img *img);
void    draw_b_line(t_img *img);
void    draw_b_square(t_img *img);
void    draw_block(t_img *obstacle);
void	draw1(t_data *data);
void	draw2(t_data *data);
int	next_img(int keycode, t_data *data);


void	draw_up(t_data *data);
void    draw_down(t_data *data);
void    draw_right(t_data *data);
void    draw_left(t_data *data);
