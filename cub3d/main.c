#include "lib.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int	main()
{
	t_data  data;
	t_vars	vars;

	vars.x = 50;
	vars.y = 50;
	vars.lenght = 100;
	vars.color = 0x00FF0000;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth,  screenHeight, "Window");

	vars.data.img = mlx_new_image(vars.mlx, screenWidth, screenHeight);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bpp, &vars.data.line_lenght, &vars.data.endian);
	display_square(97, &vars);
	mlx_destroy_image(vars.mlx, vars.data.img);
//	mlx_key_hook(vars.win, display_square, &vars);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);

//	mlx_destroy_image(vars.mlx, vars.data.img);

	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
