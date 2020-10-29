#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"

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
	t_draw	pos_p;
}               t_img;

typedef struct	s_data
{
	t_mlx	mlx;
	t_img	buff01;
	t_img	buff02;
	int	map[MAP_WIDTH][MAP_HEIGHT];
	int	cpt;


}		t_data;

void    ft_my_pixel_put(t_img *buff, int x, int y, int color);
void    ft_draw_line(t_img *buff);
void	ft_draw_square(t_img *buff);

void	ft_draw_p_line(t_img *buff);
void    ft_draw_p_square(t_img *buff);
void    ft_draw_dir(t_img *buff);
void    ft_draw_seg(t_img *buff);

int	ft_next_img(int keycode, t_data *data);
void    ft_quit(int keycode, t_data *data);
void    ft_init_buff(t_img *img);
void	ft_init_p(t_img *buff, int x, int y, int color, int dir_x, int dir_y);
void    ft_switch_buff(t_img *buff01, t_img *buff02);

void    ft_move_up(t_draw *pos);
void    ft_move_down(t_draw *pos);
void    ft_move_right(t_draw *pos);
void    ft_move_left(t_draw *pos);
void    ft_move(int keycode, t_img *buff);

void    ft_init_map(char *file, t_data *data);
void	ft_draw_map(int tab[][24], t_img *buff);
void    ft_show_map(t_data *data);


