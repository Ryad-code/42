#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
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

int		ft_isdigit(char	c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (-1);
}

int		ft_isint(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb  = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == -1)
			return (-1);
		i++;
	}
	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (-1);
	return (0);
}

int		ft_valid_args(t_data *obj, char **av)
{
	int	i;

	i = 1;
	if (obj->len_A < 1)
		return (-1);
	while (i <= obj->len_A)
	{
		if (ft_isint(av[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
