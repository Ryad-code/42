#include "fract_ol.h"

void	ft_my_pixel_put(t_img *buff, int x, int y, int color)
{
	char	*dst;

	dst = buff->addr + (y * buff->l_len + x * (buff->bpp / 8));
	*(unsigned int *)dst = color;
}

float	ft_len(t_complex a)
{
	return (sqrt(a.nr * a.nr + a.ni * a.ni));
}

int	ft_atoi(char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
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
	if (ac == 1 || ac == 3 || ac > 4)
	{
		printf("Wrong arguments.\n");
		return (1);
	}
	if (av[1][0] != 'M' && av[1][0] != 'J')
	{
		printf("Wrong argument. Choose \"M\" for Mandelbrot or \"J\" for Julia.\n");
		return (1);
	}
	if (av[1][0])
		data->arg = av[1][0];
	if (ac == 4 && av[1][0] == 'J')
	{
		data->j_r = av[2];
		data->j_i = av[3];
		if (ft_check(data->j_r) != 0 || ft_check(data->j_i) != 0)
		{
			printf("Wrong arguments for Julia set\n");
			return (1);
		}
		data->j_arg.nr = ft_set_nb(data->j_r);
		data->j_arg.ni = ft_set_nb(data->j_i);
		if ((data->j_arg.nr > 2 || data->j_arg.nr < -2)
			|| (data->j_arg.ni > 2 || data->j_arg.ni < -2))
		{
			printf("Choose a value between -2.0 and 2.0\n");
			return (1);
		}
		printf("%f, %f\n", data->j_arg.nr, data->j_arg.ni);
	}
}
