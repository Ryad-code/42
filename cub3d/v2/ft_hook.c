#include "cub3d.h"

void	ft_quit(int keycode, t_data *data)
{
	if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx.mlx, data->mlx.win);
                exit(0);
        }
}

int	next_img(int keycode, t_data *data)
{
	ft_quit(keycode, data);
	printf("%d\n", keycode);
	return (0);
}
