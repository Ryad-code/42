#include "fract_ol.h"

int main()
{
	t_data	data;
	t_complex	c;
	t_complex	d;
	int	i;
	int	y;

	c.nr = -2.000;
	c.ni = 5.000;
	d.nr = 1.000;
	d.ni = -3.000;
	i = 0;
	y = 0;
//...................................................................................
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
//...................................................................................
	data.buff01.img = mlx_new_image(data.mlx.mlx, WIDTH, HEIGHT);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
	&data.buff01.l_len, &data.buff01.endian);
//...................................................................................
	ft_init_tab(&data);
//	ft_display_tab(data);
	ft_mult(&c, &d);
	printf("%f + %f\n", c.nr, c.ni);
//	ft_test(data);
//	ft_my_pixel_put(&data.buff01, 250, 250, 0x00FF0000);
//...................................................................................
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);
//...................................................................................
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_frame, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
