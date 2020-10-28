#include "cub3d.h"

int	main()
{
	t_data data;

	data.cpt = 1;

	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 600, 600, "V2");

	data.buff01.img = mlx_new_image(data.mlx.mlx, 600, 600);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp, &data.buff01.l_len, &data.buff01.endian);

	ft_init_buff(&data.buff01);
	ft_init_map("maps/map1.txt", &data);
	ft_show_map(&data);
	
	ft_draw_map(data.map, &data.buff01);

	data.buff01.pos.x = 200;
	data.buff01.pos.y = 400;
	data.buff01.pos.color = 0x000000FF;
	ft_draw_square(&data.buff01);
	
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);

//	printf("%d\n", data.buff01.pos.x);
//	printf("%d\n", data.buff01.pos.y);
//	printf("%d\n", data.buff01.pos.color);
//	printf("%d\n", MAP_HEIGHT);
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_img, &data);

	mlx_loop(data.mlx.mlx);



}
