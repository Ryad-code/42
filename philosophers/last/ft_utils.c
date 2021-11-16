/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:13:50 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/19 11:13:59 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_digit(char c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (0);
}

int	ft_is_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5)
		return (-1);
	while (i < ac)
	{
		if (ft_is_nb(av[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_one_philo(char **av)
{
	usleep(ft_atoi(av[2]) * 1000);
	printf("%ldms philo1 died\n", ft_atoi(av[2]));
}

long	ft_atoi(char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i]
		== '\r' || str[i] == '\f' || str[i] == ' ')
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
