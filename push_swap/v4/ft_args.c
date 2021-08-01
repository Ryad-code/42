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

int		ft_is_double(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 0;
	pile = pile->next;
	while (pile != tmp)
	{
		if (nb == pile->nb)
			i++;
		pile = pile->next;
	}
	return (i);
}

int		ft_check_doubles(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	pile = pile ->next;
	while (pile != tmp)
	{
		if (ft_is_double(tmp, pile->nb) != 1)
			return (-1);
		pile = pile->next;
	}
	return (0);
}

int		ft_valid_args(t_data *obj, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac - 1 < 1)
		return (-1);
	while (i <= ac - 1)
	{
		if (ft_isint(av[i]) == -1)
			return (-2);
		i++;
	}
	if (ft_check_doubles(obj->pileA) == -1)
		return (-3);
	return (0);
}
