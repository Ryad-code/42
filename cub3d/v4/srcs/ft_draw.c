#include "../cub3d.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
        char    *dst;

        dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
        *(unsigned int*)dst = color;
}

void	ft_line(t_img *buff, t_data *data)
{
	double	tmp;
	int	i;

	tmp = (PI / 180) * data->player.angle;
	i = 0;

	while (i < 50)
	{
		ft_my_pixel_put(buff, (int)nearbyint(data->player.x + (cos(tmp) * i)), (int)nearbyint(data->player.y + (sin(tmp) * i)), 0x00FF0000);
		i++;
	}

}
