/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/01 17:43:50 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->mutex);
	pthread_mutex_lock(&philo->l_fork->mutex);
	philo->r_fork->state = philo->id;
	philo->l_fork->state = philo->id;
	ft_print(philo, 'f');
}

void	ft_drop_forks(t_philo *philo)
{
	philo->r_fork->state = 0;
	philo->l_fork->state = 0;
	pthread_mutex_unlock(&philo->r_fork->mutex);
	pthread_mutex_unlock(&philo->l_fork->mutex);
}

int	ft_eat(t_philo *philo)
{
	int	res;

	ft_print(philo, 'e');
	philo->last_meal = ft_get_time1(philo);
	philo->nb_meal++;
	res = ft_usleep(philo, philo->arg->to_eat);
	if (res < 0)
	{
		ft_print(philo, 'd');
		ft_drop_forks(philo);
		return (-1);
	}
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	int	res;

	ft_print(philo, 's');
	res = ft_usleep(philo, philo->arg->to_sleep);
	if (res < 0)
	{
		ft_print(philo, 'd');
		return (-1);
	}
	return (0);
}

int	ft_think(t_philo *philo)
{
	ft_print(philo, 't');
	while (philo->r_fork->state != 0 && philo->l_fork->state != 0)
	{
		if (ft_get_time(philo, philo->last_meal) > philo->arg->to_die)
		{
			ft_print(philo, 'd');
			return (-1);
		}
	}
	return (0);
}
