/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/11 12:46:01 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_table *tmp;

	tmp = (t_table*)arg;
	pthread_mutex_lock(&tmp->forks[1]);
	printf("fork 1 locked\n");
	printf("philo is eating...\n");
	sleep(1);
	pthread_mutex_unlock(&tmp->forks[1]);
	printf("fork unlocked\n");
	printf("philo is sleeping\n");
	sleep(1);
	printf("Now wait!\n");
	return (NULL);
}
