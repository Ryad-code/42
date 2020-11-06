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

void    ft_init_map(char *file, t_data *data)
{
        int     i;
        int     j;
        int     fd;
        char    *line;

        i = 0;
        j = 0;
        fd = open(file, O_RDONLY);
        while (i < MAP_WIDTH)
        {
                get_next_line(fd, &line);
                while (j < MAP_HEIGHT)
                {
                        data->map[i][j] = line[j] - 48;
                        j++;
                }
                j = 0;
                i++;
        }
}

void    ft_draw_map(int tab[][24], t_img *buff)
{
        int i;
        int j;

        i = 0;
        j = 0;
        while (i < SIZE)
        {
                while (j < SIZE)
                {
                        if (tab[i][j] == 1)
                                ft_draw_square(buff, j * SIZE, i * SIZE, SIZE);
                        j++;
                }
                j = 0;
                i++;
        }
}

void    ft_show_map(t_data *data)
{
        int i;
        int j;

        i = 0;
        j = 0;
        while (i < MAP_WIDTH)
        {
                while (j < MAP_HEIGHT)
                {
                        printf("%d", data->map[i][j]);
                        j++;
                }
                printf("\n");
                j = 0;
                i++;
        }
}
