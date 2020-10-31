#include "cub3d.h"

int	main()
{
	t_data data;

	data.cpt = 1;

	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 576, 576, "V2");

	data.buff01.img = mlx_new_image(data.mlx.mlx, 576, 576);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
	&data.buff01.l_len, &data.buff01.endian);

	ft_init_buff(&data.buff01);				//Initialisation
	ft_init_p(&data.buff01, 200, 200, 0x0008000, 0, 0, 0);
	ft_init_map("maps/map1.txt", &data);
//	ft_show_map(&data);
	
	ft_draw_map(data.map, &data.buff01);			//Affichage de la map

	ft_draw_p_square(&data.buff01);				//Affichage player

	ft_get_dir(&data.buff01);
//	ft_draw_dir(&data.buff01);				//Affichage direction
	
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);

	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_img, &data);

	mlx_loop(data.mlx.mlx);



}
