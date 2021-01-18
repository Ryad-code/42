#include "cub3d.h"

int main()
{
	t_data data;

	data.cpt = 1;
	data.buff01.player.x = 25;
	data.buff01.player.y = 25;
	data.buff01.player.angle = 40;


	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, MAP_WIDTH * SIZE, MAP_HEIGHT * SIZE, "V3");

	data.buff01.img = mlx_new_image(data.mlx.mlx, MAP_WIDTH * SIZE, MAP_HEIGHT * SIZE);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
        &data.buff01.l_len, &data.buff01.endian);

	ft_init_grid(&data);
	ft_get_map("maps/map01.txt", &data);
	ft_draw_map(&data, &data.buff01);

//	ft_my_pixel_put(&data.buff01, data.buff01.player.y, data.buff01.player.y, 0x00FF0000);
	ft_raycast(&data, &data.buff01);

	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);
	
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_frame, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
