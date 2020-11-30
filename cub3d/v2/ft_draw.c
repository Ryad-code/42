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
		ft_my_pixel_put(buff, x + i, y, 0x000000FF);
		buff->tab[x + i][y] = 1;
                i++;
        }
}

void    ft_draw_line2(t_img *buff, int x, int y, int size, int color)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_my_pixel_put(buff, x, y + i, color + size / 2);
		i++;
	}
}

void    ft_draw_line2_1(t_img *buff, int x, int y, int size, int color)
{
        int i;

        i = 0;
        while (i < size)
        {
                ft_my_pixel_put(buff, x, y + i, color);
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
                i++;
        }
}
