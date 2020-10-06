#include <stdio.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_lenght;
	int	endian;

}		t_data;

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	display_line(t_data *data, int x, int y, int lenght, int color)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		my_pixel_put(data, x + i, y, color);
		i++;
	}
}

void	display_square(t_data *data, int x, int y, int lenght, int color)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		display_line(data, x , y + i, lenght, color);
		i++;
	}
}

int	main()
{
	int	i;
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024,  1024, "Window");

	data.img = mlx_new_image(mlx, 1024, 1024);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_lenght, &data.endian);
//	display_line(&data, 50, 100, 100, 0x00FF0000);
	display_square(&data, 50, 100, 100, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);

	mlx_loop(mlx);

	return (0);
}
