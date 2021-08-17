/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/17 17:00:23 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->mutex);
	pthread_mutex_lock(&philo->l_fork->mutex);
	philo->r_fork->state = philo->id;
	philo->l_fork->state = philo->id;
	printf("%ldms philo%d has taken forks\n",
		ft_get_time(philo, philo->time->start), philo->id);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork->mutex);
	pthread_mutex_unlock(&philo->l_fork->mutex);
	philo->r_fork->state = 0;
	philo->l_fork->state = 0;
}

int	ft_eat(t_philo *philo)
{
	int	res;

	printf("%ldms philo%d is eating\n",
		ft_get_time(philo, philo->time->start), philo->id);
	philo->last_meal = ft_get_time1(philo);
	res = ft_usleep(philo, philo->arg->to_eat);
	if (res < 0)
	{
		philo->arg->nb_philo--;
		printf("%ldms philo%d died\n",
			ft_get_time(philo, philo->time->start), philo->id);
		return (-1);
	}
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	int	res;

	printf("%ldms philo%d is sleeping\n",
		ft_get_time(philo, philo->time->start), philo->id);
	res = ft_usleep(philo, philo->arg->to_sleep);
	if (res < 0)
	{
		philo->arg->nb_philo--;
		printf("%ldms philo%d died\n",
			ft_get_time(philo, philo->time->start), philo->id);
		return (-1);
	}
	return (0);
}

int	ft_think(t_philo *philo)
{
	while (philo->r_fork->state != 0 && philo->l_fork->state != 0)
	{
		if (ft_get_time(philo, philo->last_meal) > philo->arg->to_die)
		{
			philo->arg->nb_philo--;
			printf("%ldms philo%d died\n",
				ft_get_time(philo, philo->time->start), philo->id);
			return (-1);
		}
	}
	return (0);
}
