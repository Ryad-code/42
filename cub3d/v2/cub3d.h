#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}		t_mlx;

typedef struct	s_draw
{
	int	x;
	int	y;
	int	color;
}		t_draw;

typedef struct  s_img
{
        void    *img;
        char    *addr;
        int     l_len;
        int     bpp;
        int     endian;
	t_draw	pos;
}               t_img;

typedef struct	s_data
{
	t_mlx	mlx;
	t_img	buff01;
	t_img	buff02;
	int	cpt;


}		t_data;

void	init_buff01(t_img *img);

void    my_pixel_put(t_img *img, int x, int y, int color);
void    draw_line(t_img *img);
void	draw_square(t_img *img);

int	next_img(int jeycode, t_data *data);

void	ft_quit(int keycode, t_data *data);

void	ft_parser(int tab[][24], t_img *buff);



