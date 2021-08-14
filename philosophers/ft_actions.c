/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/14 15:30:48 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo*)arg;

	printf("t = %ld\n", ft_get_time1(tmp, tmp->time->start));
//	sleep(1);
	ft_sleep5ms(tmp);
	printf("t = %ld\n", ft_get_time1(tmp, tmp->time->start));

//	pthread_mutex_lock(tmp->r_fork);
//	pthread_mutex_lock(tmp->l_fork);
	
//	printf("%ldms philo%d is eating...\n", ft_get_time1(tmp, tmp->time->start), tmp->id);
//	ft_sleep5ms(tmp/*, tmp->arg->to_eat*/);
//	usleep(1000000);	
//	pthread_mutex_unlock(tmp->r_fork);
//	pthread_mutex_unlock(tmp->l_fork);

//	printf("%ldms philo%d is sleeping\n", ft_get_time1(tmp, tmp->time->start), tmp->id);
//	ft_sleep(tmp, tmp->arg->to_sleep);
//	printf("%dms philo%d now thinking!\n", ft_get_time(tmp, tmp->time->start) / 1000, tmp->id);
//	while (pthread_mutex_lock(tmp->r_fork) != 0 && pthread_mutex_lock(tmp->l_fork) != 0)
//	{
//		
//	}
	return (NULL);
}
