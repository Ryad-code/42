/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:18:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/17 17:40:53 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*tmp;
	int		res;

	tmp = (t_philo *)arg;
	if (tmp->id % 2 == 0 && tmp->last_meal == tmp->time->start)
		usleep(10);
	ft_grab_forks(tmp);
	res = ft_eat(tmp);
	if (res < 0)
		return (NULL);
	ft_drop_forks(tmp);
	res = ft_sleep(tmp);
	if (res < 0)
		return (NULL);
	res = ft_think(tmp);
	if (res < 0)
		return (NULL);
	return (NULL);
}

void	*ft_routine1(void *arg)
{
	t_philo	*tmp;
	int		nb_philo;

	tmp = arg;
	nb_philo = tmp->arg->nb_philo;
	while (nb_philo == tmp->arg->nb_philo1)
	{
		ft_routine(arg);
	}
	return (NULL);
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
