#include "cub3d.h"

void    my_pixel_put(t_img *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
        *(unsigned int*)dst = color;
}

void    draw_line(t_img *img)
{
        int i;

        i = 0;
        while (i < 50)
        {
                my_pixel_put(img, img->pos.x + i, img->pos.y, img->pos.color);
                i++;
        }
}

void    draw_square(t_img *img)
{
        int i;

        i = 0;
        while (i < 50)
        {
                draw_line(img);
                img->pos.y++;
                i++;
        }
        img->pos.y -= 50;
}
