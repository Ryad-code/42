#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SIZE 24
#define PI 3.1415926535

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}		t_mlx;

typedef struct	s_draw
{
	int	x;
	int	y;
	double	dir_x;
	double	dir_y;
	int	angle;
	int	color;
}		t_draw;

typedef struct  s_img
{
        void    *img;
        char    *addr;
        int     l_len;
        int     bpp;
        int     endian;
	t_draw	map;
	t_draw	player;
	int	tab[576][576];
}               t_img;

typedef struct	s_data
{
	t_mlx	mlx;
	t_mlx	f_mlx;
	t_img	buff01;
	t_img	buff02;
	int	cpt;


}		t_data;

void    ft_my_pixel_put(t_img *buff, int x, int y, int color);
void    ft_draw_line(t_img *buff, int x, int y, int size);
void    ft_draw_line2(t_img *buff, int x, int y, int size);
void	ft_draw_square(t_img *buff, int x, int y, int size);

void	ft_draw_p_line(t_img *buff);
void    ft_draw_p_square(t_img *buff);
void	ft_get_dir(t_img *buff);

int	next_img(int keycode, t_data *data);

void    ft_init_grid(t_img *buff);
void	ft_display_map(t_img *buff);
void	ft_display_player(t_img *buff);

void	ft_ray_right(t_img *buff);
void	ft_ray_down(t_img *buff);
void	ft_ray_left(t_img *buff);
void	ft_ray_up(t_img *buff);
void	test(t_img *buff);

void	ft_switch_img(int keycode, t_data *data);
