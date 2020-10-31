#include "cub3d.h"

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
        ft_init_buff(buff);
        while (i < SIZE)
        {
                while (j < SIZE)
                {
                        if (tab[i][j] == 1)
                                ft_draw_square(buff);
			buff->pos.color += 70;  //affichage
                        buff->pos.x += SIZE;
                        j++;
                }
                buff->pos.x = 0;
                buff->pos.y += SIZE;
                j = 0;
                i++;
        }
        buff->pos.y = 0;
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
