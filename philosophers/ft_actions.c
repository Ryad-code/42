/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/11 14:44:46 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo*)arg;
	pthread_mutex_lock(tmp->r_fork);
	pthread_mutex_lock(tmp->l_fork);
	printf("philo%d is eating...\n", tmp->id);
	sleep(1);
	pthread_mutex_unlock(tmp->r_fork);
	pthread_mutex_unlock(tmp->l_fork);
	printf("philo%d is sleeping\n", tmp->id);
	sleep(1);
	printf("philo%d now waiting!\n", tmp->id);
	return (NULL);
}
