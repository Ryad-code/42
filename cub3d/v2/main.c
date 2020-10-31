#include "cub3d.h"

int	main()
{
//	int	tab[576][576];
	t_data	data;

	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 576, 576, "V2");

	data.buff01.img = mlx_new_image(data.mlx.mlx, 576, 576);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
	&data.buff01.l_len, &data.buff01.endian);

	data.buff01.player.x = 200;
	data.buff01.player.y = 200;
	data.buff01.player.angle = 30;		//Angle par rapport a l'abcisse
	data.buff01.player.color = 0x00FF0000;

	data.buff01.map.x = 400;
	data.buff01.map.y = 50;
	data.buff01.map.color = 0x000000FF;

	ft_draw_line2(&data.buff01);
	ft_draw_p_square(&data.buff01);

//	ft_get_dir(&data.buff01);
//	ft_ray(&data.buff01);
	test(&data.buff01);

	mlx_hook(data.mlx.win, 2, 1L<<0, next_img, &data);	
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);

	mlx_loop(data.mlx.mlx);



}
