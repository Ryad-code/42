#include <stdio.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;

}		t_data;


int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024,  1024, "Window");

	data.img = mlx_new_image(mlx, 512, 512);
//	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenght, &data.endian);
	


	mlx_loop(mlx);

	return (0);
}
