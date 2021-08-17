/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/17 16:33:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
		pthread_mutex_lock(&philo->r_fork->mutex);
		pthread_mutex_lock(&philo->l_fork->mutex);
		philo->r_fork->state = philo->id;
		philo->l_fork->state = philo->id;
		printf("%ldms philo%d has taken forks\n", ft_get_time(philo, philo->time->start), philo->id);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork->mutex);
	pthread_mutex_unlock(&philo->l_fork->mutex);
	philo->r_fork->state = 0;
	philo->l_fork->state = 0;
}

int		ft_eat(t_philo *philo)
{
	int res;

	printf("%ldms philo%d is eating\n", ft_get_time(philo, philo->time->start), philo->id);
	philo->last_meal = ft_get_time1(philo);
	res  = ft_usleep(philo, philo->arg->to_eat);
	if (res < 0)
	{
		philo->arg->nb_philo--;
		printf("%ldms philo%d died\n", ft_get_time(philo, philo->time->start), philo->id);
		return (-1);
	}
	return (0);
}

int		ft_sleep(t_philo *philo)
{
	int res;

	printf("%ldms philo%d is sleeping\n", ft_get_time(philo, philo->time->start), philo->id);
	res = ft_usleep(philo, philo->arg->to_sleep);
	if (res < 0)
	{
		philo->arg->nb_philo--;	
		printf("%ldms philo%d died\n", ft_get_time(philo, philo->time->start), philo->id);
		return (-1);
	}
	return (0);
}

int		ft_think(t_philo *philo)
{
	int i;

	i = 0;
	while (philo->r_fork->state != 0 && philo->l_fork->state != 0)
	{
		if (ft_get_time(philo, philo->last_meal) > philo->arg->to_die)
		{
			i++;
			philo->arg->nb_philo--;
			printf("%ldms philo%d died\n", ft_get_time(philo, philo->time->start), philo->id);
			return (-1);
		}
//		printf("i = %d\n", i);
	}
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo *tmp;
	int		res;

	tmp = (t_philo*)arg;
	if (tmp->id % 2 == 0 && tmp->last_meal == tmp->time->start)//....Decalage
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
/*	ft_eat(tmp);
	ft_drop_forks(tmp);
	ft_sleep(tmp);
	ft_think(tmp);*/
	return (NULL);
}

void	*ft_routine1(void *arg)
{
	t_philo	*tmp;
	int		nb_philo;

	tmp = arg;
	nb_philo = tmp->arg->nb_philo;
	while (nb_philo == tmp->arg->nb_philo)
	{
		ft_routine(arg);
	}
	return (NULL);
}
