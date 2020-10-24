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
        while (i < 100)
        {   
                my_pixel_put(img, img->x + i, img->y, img->color);
                i++;
        }   
}

void	draw_square(t_img *img)
{
	int i;

	i = 0;
	while (i < 100)
	{
		draw_line(img);
		img->y++;
		i++;
	}
	img->y -= 100;
}
