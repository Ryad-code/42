#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400
#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define SIZE 20
#define	BLOCK_COLOR 0x000000FF
#define SKY_COLOR 0x0B0E0E6
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
	double	angle;
	double	delta;
	double	r_len;
	int	color;
}		t_player;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int		l_len;
	int		bpp;
	int		endian;
}		t_img;

typedef struct	s_descriptor
{
	int	s_width;
	int	s_height;
	char 	*resolution;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	char	*f;
	char	*c;
//	int     map[MAP_WIDTH][MAP_HEIGHT];
//	int     grid[][MAP_HEIGHT * SIZE];
}		t_descriptor;

typedef struct	s_data
{
	t_mlx		mlx;
	t_img		buff01;
	t_img		buff02;
	t_player	player;
	t_descriptor	descriptor;
	int		map[MAP_WIDTH][MAP_HEIGHT];		//à retirer
	int		grid[SCREEN_WIDTH][SCREEN_HEIGHT];		//
	int		cpt;
}			t_data;


void	ft_my_pixel_put(t_img *buff, int x, int y, int color);	//FT_DRAW.C
void	ft_draw_line(t_data *data, t_img *buff, int x, int y);
void    ft_draw_line2(t_data *data, t_img *buff, int x, int y);
void	ft_draw_block(t_data *data, t_img *buff, int x, int y);
void	ft_draw_screen(t_data *data, t_img *buff, int x, int y);

void    ft_init_grid(t_data *data);				//FT_DESCRIPTOR.C
void    ft_read_fd(const char *file, t_data *data);
void	ft_get_map(t_data *data, int fd, char *line);
void    ft_draw_map(t_data *data, t_img *buff);

int	ft_atoi(char *str);					//FT_PARSER.C
void	ft_check_line(t_data *data, char *line);
void	ft_get_lines(t_data *data, int fd, char *line);

void	ft_init_buff(t_data *data, t_img *buff);		//FT_FRAME.C
int	ft_next_frame(int keycode, t_data *data);

void	ft_keycode(int keycode, t_data *data, t_img *buff);	//FT_HOOKS.C
void	ft_move_player(int keycode, t_data *data, t_img *buff);
void    ft_turn_player(int keycode, t_data *data);
void	ft_move(t_data *data, t_img *buff);
void	ft_move_back(t_data *data, t_img *buff);
void	ft_move_right(t_data *data, t_img *buff);
void	ft_move_left(t_data *data,  t_img *buff);

void	ft_get_delta(t_data *data);				//FT_RAY.C
void	ft_ray_right(t_data *data, t_img *buff);
void	ft_ray_left(t_data *data, t_img *buff);			//Changer prototypes
void	ft_ray_up(t_data *data, t_img *buff);			//
void	ft_ray_down(t_data *data, t_img *buff);			//
void	ft_ray(t_data *data, t_img *buff);			//
void    ft_raycast(t_data *data, t_img *buff);
