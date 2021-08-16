/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/16 16:58:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
//	if (philo->r_fork->state == 0 && philo->l_fork->state == 0)
//	{
		pthread_mutex_lock(&philo->r_fork->fork);
		pthread_mutex_lock(&philo->l_fork->fork);
		philo->r_fork->state = 1;
		philo->l_fork->state = 1;
//	}
//	else
//		ft_grab_forks(philo);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork->fork);
	pthread_mutex_unlock(&philo->l_fork->fork);
	philo->r_fork->state = 0;
	philo->l_fork->state = 0;
}

void	*ft_routine(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo*)arg;

	if (tmp->id % 2 == 0)//.................???
		ft_sleep(tmp, 1);
//	pthread_mutex_lock(&tmp->r_fork->fork);
//	pthread_mutex_lock(&tmp->l_fork->fork);
	ft_grab_forks(tmp);
	printf("%ldms philo%d is holding forks\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	
	printf("%ldms philo%d is eating\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	tmp->last_meal = ft_get_time(tmp, tmp->time->start);
	ft_sleep(tmp, tmp->arg->to_eat);
//	pthread_mutex_unlock(&tmp->r_fork->fork);
//	pthread_mutex_unlock(&tmp->l_fork->fork);
	ft_drop_forks(tmp);

	printf("%ldms philo%d is sleeping\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	ft_sleep(tmp, tmp->arg->to_sleep);
	printf("%ldms philo%d is thinking\n", ft_get_time(tmp, tmp->time->start), tmp->id);
	while (tmp->life > 0 && (tmp->r_fork->state != 0 || tmp->l_fork->state != 0))
	{
		if (ft_get_time(tmp, tmp->last_meal) >= tmp->arg->to_die)
		{
			tmp->life = -1;
			printf("%ldms philo%d is dead\n", ft_get_time(tmp, tmp->time->start), tmp->id);
			break;
		}
	}
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
