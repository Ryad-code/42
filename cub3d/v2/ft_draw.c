#include "cub3d.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
        char    *dst;

        dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
	*(unsigned int*)dst = color;
	
}

void    ft_draw_line(t_img *buff, int x, int y, int size)
{
        int i;

        i = 0;
        while (i < size)
        {
                ft_my_pixel_put(buff, x + i, y, buff->map.color);
		buff->tab[x + i][y] = 1;
                i++;
        }
}

void    ft_draw_line2(t_img *buff, int x, int y, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_my_pixel_put(buff, x, y + i, buff->map.color);
		buff->tab[x][y + i] = 1;
		i++;
	}
}

void    ft_draw_square(t_img *buff, int x, int y, int size)
{
        int i;

        i = 0;
        while (i < size)
        {
                ft_draw_line(buff, x, y + i, size);
                buff->map.y++;
                i++;
        }
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
