#include "cub3d.h"

void	ft_parser(int tab[][24], t_img *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 24)
	{
		while (j < 24)
		{
			if (tab[i][j] == 1)
				draw_square(buff);
			buff->pos.x += 50;
//			printf("%d, ", tab[i][j]);
			j++;
		}
//		printf("\n");
		buff->pos.x -= 1200;		
		buff->pos.y += 50;
		j = 0;
		i++;
	}
}
