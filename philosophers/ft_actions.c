/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/14 19:08:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo*)arg;

	pthread_mutex_lock(tmp->r_fork);
	pthread_mutex_lock(tmp->l_fork);
	
	printf("%ldms philo%d is eating\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	ft_sleep(tmp, tmp->arg->to_eat);
	pthread_mutex_unlock(tmp->r_fork);
	pthread_mutex_unlock(tmp->l_fork);

	printf("%ldms philo%d is sleeping\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	ft_sleep(tmp, tmp->arg->to_sleep);
	printf("%ldms philo%d is thinking\n", ft_get_time(tmp, tmp->time->start), tmp->id);
/*	while ((pthread_mutex_lock(tmp->r_fork) != 0 && pthread_mutex_lock(tmp->l_fork) != 0) || tmp->life < 0)
	{
		if (ft_get_time(tmp, (tmp->time->time1.tv_sec * 1000) + (tmp->time->time1.tv_usec / 1000)) >= tmp->arg->to_die)
		{
			tmp->life = -1;
			printf("%ldms philo%d is dead\n", ft_get_time(tmp, tmp->time->start), tmp->id);
		}
	}*/
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
