#include "../cub3d.h"

void	ft_keycode(int keycode, t_data *data, t_img *buff)
{
	double  tmp;

	tmp = (PI / 180) * data->player.angle;
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	ft_turn(keycode, data);
	ft_direction(keycode, data);
	ft_draw_map(data, buff);
	ft_line(buff, data);
	printf("[%d]", (int)floor(data->player.x / B_SIZE));
	printf("[%d]\n", (int)floor(data->player.y / B_SIZE));
	printf("x = %lf\n", data->player.x / B_SIZE);
	printf("y = %lf\n", data->player.y / B_SIZE);
	printf("grid = %d\n\n", data->map.grid[(int)floor(data->player.x / B_SIZE)]
	[(int)floor((data->player.y / B_SIZE))]);
	printf("%d\n", data->player.angle);
}

void 	ft_turn(int keycode, t_data *data)
{
	if (keycode == 97)
		data->player.angle -= 2;
	if (keycode == 122)
		data->player.angle += 2;
}

void	ft_direction(int keycode, t_data *data)
{
	double	tmp;
	
	tmp = (PI / 180) * data->player.angle;

	if (keycode == 65361 && data->map.grid[((int)floor(data->player.x + (2 * cos(tmp - (PI / 2)))) / B_SIZE)]
	[((int)floor(data->player.y + (2 * sin(tmp - (PI / 2)))) / B_SIZE)] != 1 )
	{
		data->player.x += 2 * cos(tmp - (PI / 2));
		data->player.y += 2 * sin(tmp - (PI / 2));
	}
	else if(keycode == 65362 && data->map.grid[((int)floor(data->player.x + (2 * cos(tmp))) / B_SIZE)]
        [((int)floor(data->player.y + (2 * sin(tmp))) / B_SIZE)] != 1)
	{
		data->player.x += 2 * cos(tmp);
		data->player.y += 2 * sin(tmp);
	}
	else if (keycode == 65363 && data->map.grid[((int)floor(data->player.x + (2 * cos(tmp + (PI / 2)))) / B_SIZE)]
        [((int)floor(data->player.y + (2 * sin(tmp + (PI / 2)))) / B_SIZE)] != 1)
	{
		data->player.x += 2 * cos(tmp + (PI / 2));
		data->player.y += 2 * sin(tmp + (PI / 2));
	}
	else if (keycode == 65364 && data->map.grid[((int)floor(data->player.x + (2 * cos(tmp + PI))) / B_SIZE)]
        [((int)floor(data->player.y + (2 * sin(tmp + PI))) / B_SIZE)] != 1)
	{
		data->player.x += 2 * cos(tmp + PI);
		data->player.y += 2 * sin(tmp + PI);
	}
}
