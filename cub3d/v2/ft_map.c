#include "cub3d.h"

void	ft_init_grid(t_img *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 576)
	{
		while (j < 576)
		{
			buff->tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_display_map(t_img *buff)
{
	buff->map.color = 0x000000FF;

	ft_draw_line2(buff, 50, 0, 576);
        ft_draw_line2(buff, 526, 0, 576);
        ft_draw_line(buff, 0, 50, 576);
        ft_draw_line(buff, 0, 526, 576);

	ft_draw_line2(buff, 100, 200, 50);
	ft_draw_line2(buff, 100, 300, 50);
	ft_draw_line(buff, 150, 100, 200);
	ft_draw_line2(buff, 350, 100, 100);
	ft_draw_line(buff, 400, 450, 100);
}

void	ft_display_player(t_img *buff)
{
//	buff->player.x = 280;
//	buff->player.y = 400;
//	buff->player.color = 0x00FF0000;

	ft_draw_p_square(buff);
}
