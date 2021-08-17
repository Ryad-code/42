/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/17 15:07:06 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		printf("%ldms philo%d is holding forks\n", ft_get_time(philo, philo->time->start), philo->id);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);

}

void	ft_eat(t_philo *philo)
{
	printf("%ldms philo%d is eating\n", ft_get_time(philo, philo->time->start), philo->id);
	philo->last_meal = ft_get_time1(philo);
	ft_usleep(philo, philo->arg->to_eat);
}

void	ft_sleep(t_philo *philo)
{
	printf("%ldms philo%d is sleeping\n", ft_get_time(philo, philo->time->start), philo->id);
	ft_usleep(philo, philo->arg->to_sleep);
}

void	*ft_routine(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo*)arg;
	if (tmp->id % 2 == 0 && tmp->last_meal == tmp->time->start)//....Decalage
		usleep(10);
	ft_grab_forks(tmp);
	ft_eat(tmp);
	ft_drop_forks(tmp);
	ft_sleep(tmp);
	return (NULL);
}

void	*ft_routine1(void *arg)
{
	t_philo	*tmp;
	int		nb_philo;

	tmp = arg;
	nb_philo = tmp->arg->nb_philo;
	while (tmp->life > 0 && nb_philo == tmp->arg->nb_philo)
	{
		ft_routine(arg);
	}
	return (NULL);
}
