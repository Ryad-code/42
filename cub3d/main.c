#include "cub3d.h"

int	main()
{
	t_data data;
	
	data.img.x = 0;
	data.img.y = 0;
	data.img.color = 0x00FF0000;

	data.buff.x = 0;
	data.buff.y = 0;
	data.buff.color = 0x00FF0000;

	data.img.x_o = 400;
	data.img.y_o = 0;
	data.img.color_o = 0x000000FF;

	data.buff.x_o = 400;
	data.buff.y_o = 0;
	data.buff.color_o = 0x000000FF;

	data.cpt = 1;

	data.mlx.ptr = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.ptr, 1000, 1000, "La vie est un échec");

	data.img.img = mlx_new_image(data.mlx.ptr, 1000, 1000);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.l_len, &data.img.endian);

	data.buff.img = mlx_new_image(data.mlx.ptr, 1000, 1000);
	data.buff.addr = mlx_get_data_addr(data.buff.img, &data.buff.bpp, &data.buff.l_len, &data.buff.endian);
	
	draw_square(&data.img);
	draw_block(&data.img);

	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.img.img, 0, 0);

//	mlx_key_hook(data.mlx.win, next_img, &data);

	mlx_hook(data.mlx.win, 2, 1L<<0, next_img, &data);

	mlx_loop(data.mlx.ptr);
}
