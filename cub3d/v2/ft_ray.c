#include "cub3d.h"

void	ft_get_dir(t_img *buff)
{
	buff->player.angle = (PI / 180) * buff->player.angle;
	buff->player.dir_x = cos(buff->player.angle); 
	buff->player.dir_y = sin(buff->player.angle);

/*	printf("x = %d\n", buff->player.x);
	printf("y = %d\n", buff->player.y);
	printf("dirx = %lf\n", buff->player.dir_x);
	printf("diry = %lf\n", buff->player.dir_y);*/
}

void	ft_ray(t_img *buff)
{
	double delta_y;
	int i;

	i = 1;

	delta_y = buff->player.dir_y / buff->player.dir_x;
	buff->player.dir_x = 1;
	buff->player.dir_y = delta_y;
	while (buff->tab[buff->player.x + i][buff->player.y] == 0)
	{
		buff->player.dir_y += delta_y;
		buff->player.dir_x++;
		ft_my_pixel_put(buff, buff->player.x + buff->player.dir_x, buff->player.y + (int)nearbyint(buff->player.dir_y), 0x00FF0000);
		i++;
	}
}

void	test(t_img *buff)
{
	int i;

	i = 0;
	while (i < 3)
	{
		buff->player.angle = i * 10;;
		ft_get_dir(buff);
		ft_ray(buff);
		i++;
	}
}
