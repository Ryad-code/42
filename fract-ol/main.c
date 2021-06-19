#include "fract_ol.h"

int main(int ac, char **av)
{
	t_data	data;
	data.precision = 0.01;
	data.scale = 6;
	data.it_max = 50;
	data.cpt = 1;

	if (ft_args(ac, av, &data) == 1)
		return (1);
//...................................................................................
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
//...................................................................................
	data.buff01.img = mlx_new_image(data.mlx.mlx, WIDTH, HEIGHT);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
	&data.buff01.l_len, &data.buff01.endian);
//...................................................................................
	ft_init_tab(&data);
	ft_set_fract(&data, &data.buff01);
//...................................................................................
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);
//...................................................................................
	mlx_mouse_hook(data.mlx.win, ft_next_frame, &data);
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_key_hook, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
