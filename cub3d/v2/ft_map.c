#include "cub3d.h"

void	ft_init(t_img *buff)
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
