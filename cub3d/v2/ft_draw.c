#include "cub3d.h"

void    ft_my_pixel_put(t_img *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
        *(unsigned int*)dst = color;
}

void    ft_draw_line(t_img *img)
{
        int i;

        i = 0;
        while (i < 25)
        {
                ft_my_pixel_put(img, img->pos.x + i, img->pos.y, img->pos.color);
                i++;
        }
}

void    ft_draw_square(t_img *img)
{
        int i;

        i = 0;
        while (i < 25)
        {
                ft_draw_line(img);
                img->pos.y++;
                i++;
        }
        img->pos.y -= 25;
}

void    ft_draw_map(int tab[][24], t_img *buff)
{
        int i;
        int j;

        i = 0;
        j = 0;
	ft_init_buff(buff);
        while (i < 24)
        {
                while (j < 24)
                {
                        if (tab[i][j] == 1)
                                ft_draw_square(buff);
			buff->pos.x += 25;
                        j++;
                }
                buff->pos.x -= 600;
                buff->pos.y += 25;
                j = 0;
                i++;
        }
        buff->pos.y -= 600;
}
