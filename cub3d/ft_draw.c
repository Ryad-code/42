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

void	draw_b_line(t_img *img)
{
	int i;

	i = 0;
	while (i < 100)
	{
		my_pixel_put(img, img->x_o + i, img->y_o, img->color_o);
		i++;
	}
}

void	draw_b_square(t_img *img)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		draw_b_line(img);
		img->y_o++;
		i++;
	}
	img->y_o -= 100;
}

void	draw_block(t_img *img)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		draw_b_square(img);
		img->y_o += 100;
		i++;
	}
	img->y_o -= 400;
}
