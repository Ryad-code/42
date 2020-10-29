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
        while (i < SIZE)
        {
                ft_my_pixel_put(buff, buff->pos.x + i, buff->pos.y, buff->pos.color);
                i++;
        }
}

void    ft_draw_square(t_img *buff)
{
        int i;

        i = 0;
        while (i < SIZE)
        {
                ft_draw_line(buff);
                buff->pos.y++;
                i++;
        }
        buff->pos.y -= SIZE;
}

void    ft_draw_p_line(t_img *buff)
{
        int i;

        i = 0;
        while (i < (SIZE / 6))
        {
                ft_my_pixel_put(buff, buff->pos_p.x + i, buff->pos_p.y, buff->pos_p.color);
		i++;
        }
}

void    ft_draw_p_square(t_img *buff)
{
        int i;

        i = 0;
        while (i < (SIZE / 6))
        {
                ft_draw_p_line(buff);
		buff->pos_p.y++;
                i++;
        }
        buff->pos_p.y -= (SIZE / 6);
}

void	ft_draw_dir(t_img *buff)
{
	int i;
	
	i = 0;
	while (i < (SIZE / 6))
	{
		buff->pos_p.x += buff->pos_p.dir_x;
		buff->pos_p.y += buff->pos_p.dir_y;
		buff->pos_p.color += 1000;
		ft_draw_p_line(buff);
		buff->pos_p.x -= buff->pos_p.dir_x;
		buff->pos_p.y -= buff->pos_p.dir_y;
		buff->pos_p.color -= 1000;
		buff->pos_p.y++;
		i++;
	}
	buff->pos_p.y -= (SIZE / 6);
}

void	ft_draw_seg(t_img *buff)
{
	int i;

	i = 0;
	while (i < 50)
	{
		ft_my_pixel_put(buff, buff->pos_p.x, buff->pos_p.y,
		buff->pos_p.color);
		buff->pos_p.x += buff->pos_p.dir_x;
		buff->pos_p.y += buff->pos_p.dir_y;
		i++;
	}
	buff->pos_p.x -= 50 * buff->pos_p.dir_x;
	buff->pos_p.y -= 50 * buff->pos_p.dir_y;
}

void	ft_draw_seg2(t_img *buff)
{
	
}

