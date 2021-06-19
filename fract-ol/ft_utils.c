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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

int	ft_args(int ac, char **av, t_data *data)
{
	if (ac == 1)
	{
		printf("No argument.\n");
		return (1);
	}
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
	if (av[1][0])
		data->arg = av[1][0];
	if (ac == 4)
	{
		data->j_r = av[2];
		data->j_i = av[3];
	}
	printf("%s | %d\n", data->j_r, ft_check_arg(data->j_r));
	printf("%s | %d\n", data->j_i, ft_check_arg(data->j_i));
}

int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i] == 1))
		return (1);
/*	i++;
	if (arg[i] != '.' && arg[i] != '\0')
		return (1);
	i++;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i] == 1))
			return (1);
		i++;
	}*/
	return (0);
}
