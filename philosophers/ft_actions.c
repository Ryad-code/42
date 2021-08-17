/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/17 12:44:22 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*ft_routine(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo*)arg;

	if (ft_get_time(tmp, tmp->last_meal) >= tmp->arg->to_die)
	{
		printf("%ldms philo%d is dead\n", ft_get_time(tmp, tmp->time->start), tmp->id);
		tmp->life = -1;
		return (tmp);
	}
	if (tmp->id % 2 == 0)//.................Decalage qui pue du cul
		ft_sleep(tmp, 1);
	ft_grab_forks(tmp);
	printf("%ldms philo%d is holding forks\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	
	printf("%ldms philo%d is eating\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	tmp->last_meal = ft_get_time1(tmp);
	ft_sleep(tmp, tmp->arg->to_eat);
	ft_drop_forks(tmp);

	printf("%ldms philo%d is sleeping\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	ft_sleep(tmp, tmp->arg->to_sleep);
	printf("%ldms philo%d is thinking\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	return (NULL);
}

void	*ft_routine1(void *arg)
{
	t_philo	*tmp;

	tmp = arg;
	while (tmp->life > 0)
	{
		ft_routine(arg);
	}
	return (NULL);
}
