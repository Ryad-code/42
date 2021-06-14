#include "fract_ol.h"

int main()
{
	t_data	data;
	int	i;
	int	y;
//	complex double a;
	t_complex	a;
	t_complex	b;
	i = 0;
	y = 0;

	a.nr = 1.000000;
	a.ni = 5.000000;
	b.nr = 1.000000;
	b.ni = 5.000000;
//	a = 3 + 5i;
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
//	ft_mult(&a, &b);
//	printf("%f + %f\n", a.nr, a.ni);
	ft_test(data);
	ft_test2(data);
//	ft_my_pixel_put(&data.buff01, 250, 250, 0x00FF0000);
//...................................................................................
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);
//...................................................................................
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_frame, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
