#include "fract_ol.h"

int main()
{
	t_data	data;
	int	x;
	int	y;

	x = -2;
	y = -1;
//...................................................................................
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 500, 500, "Fract-ol");
//...................................................................................
	data.buff01.img = mlx_new_image(data.mlx.mlx, 500, 500);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
	&data.buff01.l_len, &data.buff01.endian);
//...................................................................................
	while (y < 400)
	{
		while (x < 400)
		{
			printf("%d / %d\n", x, y);
			if (ft_test(x, y) == 50)
//			ft_my_pixel_put(&data.buff01, x, y, 0x00FF0000);	
			x++;
		}
		x = 0;
		y++;
	}
	

	ft_my_pixel_put(&data.buff01, 250, 250, 0x00FF0000);
//...................................................................................
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.buff01.img, 0, 0);
//...................................................................................
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_next_frame, &data);

	mlx_loop(data.mlx.mlx);

	return (0);
}
