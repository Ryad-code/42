#include "cub3d.h"

void    ft_move_up(t_draw *pos)
{
	if (pos->y > 24)
                pos->y -= 1;
}

void    ft_move_down(t_draw *pos)
{
	if (pos->y < 552)
                pos->y += 1;
}

void    ft_move_right(t_draw *pos)
{
	if (pos->x < 552)
                pos->x += 1;
}

void    ft_move_left(t_draw *pos)
{
	if (pos->x > 48)
                pos->x -= 1;
}

void    ft_move(int keycode, t_img *buff)
{
        if (keycode == 65362)
                ft_move_up(&buff->pos_p);
        else if (keycode == 65364)
                ft_move_down(&buff->pos_p);
        else if (keycode == 65363)
                ft_move_right(&buff->pos_p);
        else if (keycode == 65361)
                ft_move_left(&buff->pos_p);
}

void	ft_turn_right(t_draw *pos)
{

}
