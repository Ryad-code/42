#include "fract_ol.h"

void    ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
	 char    *dst;

	 dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
	 *(unsigned int*)dst = color;
}

float   ft_len(t_complex a)
{
	return (sqrt(a.nr * a.nr + a.ni * a.ni));
}

int	ft_args(int ac, char **av)
{
	if (ac > 4)
	{
		 printf("Too many arguments.\n");
		 return (1);
	}
	if (av[1][0] != 'M' && av[1][0] != 'J')
	{
		printf("Wrong argument. Choose \"M\" for Mandelbrot or \"J\" for Julia.\n");
		return (1);
	}
}

