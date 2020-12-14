#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define SIZE 20
#define	BLOCK_COLOR 0x000000FF
#define PLAYER_COLOR 0x00FF0000

#define PI 3.1415926535

typedef struct  s_mlx
{
	void	*mlx;
	void	*win;
}		t_mlx;

typedef struct	s_player
{
	double	x;
	double	y;
	int	angle;
	double	delta;
	int	color;
}		t_player;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int		l_len;
	int		bpp;
	int		endian;
	t_player	player;
}		t_img;

typedef struct	s_data
{
	t_mlx	mlx;
	t_img	buff01;
	t_img	buff02;
	int	map[MAP_WIDTH][MAP_HEIGHT];
	int	grid[MAP_WIDTH * SIZE][MAP_HEIGHT * SIZE];
	int	cpt;
}		t_data;


void	ft_my_pixel_put(t_img *buff, int x, int y, int color);	//FT_DRAW.C
void	ft_draw_line(t_data *data, t_img *buff, int x, int y);
void	ft_draw_block(t_data *data, t_img *buff, int x, int y);

void    ft_init_grid(t_data *data);				//FT_MAP.C
void    ft_get_map(const char *file, t_data *data);
void    ft_draw_map(t_data *data, t_img *buff);

void	ft_init_buff(t_data *data, t_img *buff);		//FT_FRAME.C
void	ft_switch_data(t_img *from_buff, t_img *to_buff);
int	ft_next_frame(int keycode, t_data *data);

void	ft_keycode(int keycode, t_data *data, t_img *buff);	//FT_HOOKS.C
void	ft_move_player(int keycode, t_data *data, t_img *buff);
void    ft_turn_player(int keycode, t_img *buff);
void	ft_direction(t_data *data, t_img *buff);
void	ft_move_back(t_data *data, t_img *buff);
void	ft_move_right(t_data *data, t_img *buff);
void	ft_move_left(t_data *data,  t_img *buff);

void	ft_get_delta(t_img *buff);			//FT_RAY.C
void	ft_ray_right(t_data *data, t_img *buff);
void	ft_ray_left(t_data *data, t_img *buff);
void	ft_ray_up(t_data *data, t_img *buff);
void	ft_ray_down(t_data *data, t_img *buff);
void	ft_vision(t_data *data, t_img *buff);
