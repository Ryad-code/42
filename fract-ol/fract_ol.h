#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

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

typedef struct s_data
{
	t_mlx	mlx;
	t_img	buff01;
	t_img	buff02;
}		t_data;

void	ft_my_pixel_put(t_img *buff, int x, int y, int color);
int     ft_next_frame(int keycode, t_data *data);

int	ft_test(int x, int y);
