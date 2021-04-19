#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"

#define PI 3.1415926535

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
	int		dir[2];
}			t_player;

typedef struct		s_map
{
	int		width;
	int		height;
//	int		map[width][height];
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
	int		width;
	int		height;
}			t_data;

void    ft_my_pixel_put(t_img *buff, int x, int y, int color);
void	ft_line(t_img *buff, t_data *data);
int     ft_next_frame(int keycode, t_data *data);
void	ft_keycode(int keycode, t_data *data, t_img *buff);
void	ft_direction(int kaycode, t_data *data);
void	ft_turn(int keycode, t_data *data);
