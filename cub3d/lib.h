#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

typedef struct  s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_lenght;
	int	endian;
}		t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_data	data;
	int	x;
	int	y;
	int	lenght;
	int	color;
}		t_vars;


void    my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void    display_line(t_data *data, int x, int y, int lenght, int color)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		my_pixel_put(data, x + i, y, color);
		i++;
	}
}

int    display_square(int keycode, t_vars *vars)
{
	int i;

	i = 0;
	if (keycode == 97)
	{
		while (i < vars->lenght)
		{
			display_line(&vars->data, vars->x , vars->y + i, vars->lenght, vars->color);
			i++;
		}
//		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	return (0);
}

int             close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		printf("%d\n", keycode);
}

