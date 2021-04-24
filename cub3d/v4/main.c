#include "cub3d.h"

int main()
{
	t_data	data;
	int	fd;

	data.cpt = 1;
	data.player.angle = 0;
	fd = open("maps/map01.txt", O_RDONLY);

	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, S_WIDTH, S_HEIGHT, "V4");

	data.buff01.img = mlx_new_image(data.mlx.mlx, S_WIDTH, S_HEIGHT);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
        &data.buff01.l_len, &data.buff01.endian);
	
	ft_my_pixel_put(&data.buff01, data.player.x, data.player.y, 0x00FF0000);
	ft_get_grid(&data, fd);
	ft_display_grid(&data);
//	ft_draw_map(&data, &data.buff01);
//	printf("%d\n\n", data.map.grid[5][1]);

	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);

	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_frame, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
