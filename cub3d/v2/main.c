#include "cub3d.h"

int	main()
{
	t_data	data;

	data.cpt = 1;
	data.buff01.player.angle = 0;  //Initialisation player
	data.buff01.player.x = 280;
	data.buff01.player.y = 280;
	data.buff01.player.color = 0x00FF0000;

	data.mlx.mlx = mlx_init();	//Initialisation mlx
	data.mlx.win = mlx_new_window(data.mlx.mlx, 576, 576, "V2");

	data.buff01.img = mlx_new_image(data.mlx.mlx, 576, 576);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
	&data.buff01.l_len, &data.buff01.endian);

	ft_init_grid(&data.buff01);	//Initialisation MAP/GRID
	ft_init_map("maps/map01.txt", &data);
	
	ft_draw_map(data.map, &data.buff01);
//	ft_show_map(&data);
//	ft_draw_p_square(&data.buff01);	

	ft_get_dir(&data.buff01);
	ft_vision(&data.buff01);

	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);
	mlx_hook(data.mlx.win, 2, 1L<<0, next_img, &data);

	mlx_loop(data.mlx.mlx);



}
