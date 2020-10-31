#include "cub3d.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
        char    *dst;

        dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
	*(unsigned int*)dst = color;
	
}

void    ft_draw_line(t_img *buff)
{
        int i;

        i = 0;
        while (i < 200)
        {
                ft_my_pixel_put(buff, buff->map.x + i, buff->map.y, buff->map.color);
                i++;
        }
}

void    ft_draw_line2(t_img *buff)
{
	int i;

	i = 0;
	while (i < 400)
	{
		ft_my_pixel_put(buff, buff->map.x, buff->map.y + i, buff->map.color);
		buff->tab[buff->map.x][buff->map.y + i] = 1;
		i++;
	}
}

void    ft_draw_square(t_img *buff)
{
        int i;

        i = 0;
        while (i < 200)
        {
                ft_draw_line(buff);
                buff->map.y++;
                i++;
        }
        buff->map.y -= 200;
}

void    ft_draw_p_line(t_img *buff)
{
        int i;

        i = 0;
        while (i < 3)
        {
                ft_my_pixel_put(buff, buff->player.x + i, buff->player.y, buff->player.color);
		i++;
        }
}

void    ft_draw_p_square(t_img *buff)
{
        int i;

        i = 0;
        while (i < 3)
        {
                ft_draw_p_line(buff);
		buff->player.y++;
                i++;
        }
        buff->player.y -= 3;
}

int	next_img(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	else
		printf("%d\n", keycode);
}
