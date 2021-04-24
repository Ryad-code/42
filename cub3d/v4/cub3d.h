#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"

#define PI 3.1415926535
#define S_WIDTH 650
#define S_HEIGHT 650
#define G_WIDTH 13
#define G_HEIGHT 13
#define B_SIZE 50

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
}			t_mlx;

typedef struct		s_img
{
	void		*img;
	char		*addr;
	int		l_len;
	int		bpp;
	int		endian;
}			t_img;

typedef struct		s_player
{
	double		x;
	double		y;
	int		angle;
}			t_player;

typedef struct		s_map
{
	int		grid[G_WIDTH][G_HEIGHT];
	int		b_size;
}			t_map;

typedef struct		s_data
{
	t_mlx		mlx;
	t_img		buff01;
	t_img		buff02;
	t_player	player;
	t_map		map;
	int		cpt;
}			t_data;

void    ft_my_pixel_put(t_img *buff, int x, int y, int color);
void	ft_line(t_img *buff, t_data *data);

int     ft_next_frame(int keycode, t_data *data);
void	ft_keycode(int keycode, t_data *data, t_img *buff);

void	ft_direction(int kaycode, t_data *data);
void	ft_turn(int keycode, t_data *data);

void    ft_get_grid(t_data *data, int fd);
void    ft_display_grid(t_data *data);

void    ft_draw_line(t_data *data, t_img *buff, int x, int y);
void    ft_draw_block(t_data *data, t_img *buff, int x, int y);
void    ft_draw_map(t_data *data, t_img *buff);
