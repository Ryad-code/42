/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 16:41:41 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_eat(void *arg)
{
	t_data *tmp;

	tmp = (t_data*)arg;
	pthread_mutex_lock(&tmp->philo.mutex);
	pthread_mutex_lock(&tmp->table.f_mutex);
	printf("philo%d is eating\n", tmp->philo.id);
	sleep(tmp->table.to_eat);
	printf("philo%d just ate\n", tmp->philo.id);
	pthread_mutex_unlock(&tmp->philo.mutex);
	return (NULL);
}

void    *ft_sleep(void *arg)
{
	t_data *tmp;

	tmp = (t_data*)arg;
	pthread_mutex_lock(&tmp->philo.mutex);
	printf("philo%d is sleeping\n", tmp->philo.id);
	sleep(tmp->table.to_sleep);
	printf("philo%d just slept\n", tmp->philo.id);
	pthread_mutex_unlock(&tmp->philo.mutex);
	return (NULL);
}

void    *ft_think(void *arg)
{
	t_data *tmp;

	tmp = (t_data*)arg;
	pthread_mutex_lock(&tmp->philo.mutex);
	printf("philo%d is thinking\n", tmp->philo.id);
	while (pthread_mutex_unlock(&tmp->table.f_mutex) != 0)
	{
		printf("waiting...");
	}
	printf("\n");
	printf("philo%d has thought\n", tmp->philo.id);
	pthread_mutex_unlock(&tmp->philo.mutex);
	return (NULL);
}
