/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 16:20:16 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_eat(void *arg)
{
	t_data *tmp;

	tmp = (t_data*)arg;
	pthread_mutex_lock(&tmp->philo.mutex);
	tmp->philo.is_eating = 1;
	printf("philo%d is eating\n", tmp->philo.id);
	sleep(tmp->table.to_eat);
	tmp->philo.is_eating = 0;
	printf("philo%d just ate\n", tmp->philo.id);
	pthread_mutex_unlock(&tmp->philo.mutex);
	return (NULL);
}

void    *ft_sleep(void *arg)
{
	t_data *tmp;

	tmp = (t_data*)arg;
	pthread_mutex_lock(&tmp->philo.mutex);
	tmp->philo.is_sleeping = 1;
	printf("philo%d is sleeping\n", tmp->philo.id);
	sleep(tmp->table.to_sleep);
	tmp->philo.is_sleeping = 0;
	printf("philo%d just slept\n", tmp->philo.id);
	pthread_mutex_unlock(&tmp->philo.mutex);
	return (NULL);
}

/*void    *ft_think(void *arg)
{
	t_data *tmp;

	tmp = (t_data*)arg;
	tmp->philo.is_thinking = 1;
	printf("philo%d is thinking\n", tmp->philo.id);
	sleep(tmp->table.to_think);
	tmp->philo.is_thinking = 0;
	return (NULL);
}*/
