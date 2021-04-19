#include "cub3d.h"

int main()
{
	t_data data;
	data.cpt = 1;
	data.width = 1000;
	data.height = 1000;
	data.player.x = 600;
	data.player.y = 600;
	data.player.angle = 240;
	data.player.dir[0] = 1;
	data.player.dir[1] = 0;

	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, data.width, data.height, "V3");

	data.buff01.img = mlx_new_image(data.mlx.mlx, data.width, data.height);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
        &data.buff01.l_len, &data.buff01.endian);
	
	ft_my_pixel_put(&data.buff01, data.player.x, data.player.y, 0x00FF0000);

	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);

	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_frame, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
