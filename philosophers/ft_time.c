/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:59:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/13 20:22:10 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_start(t_table *table)
{
	table->time = malloc(sizeof(t_time));
	gettimeofday(&table->time->time1, NULL);
	table->time->start = table->time->time1.tv_usec;
	printf("0 ms--->START\n");
}

int		ft_get_time(t_philo *philo, int start)
{
	long tmp;

	tmp = 0;
	gettimeofday(&philo->time->time2, NULL);
	if (philo->time->time2.tv_usec >= start)
		tmp = philo->time->time2.tv_usec - start;
	else
		tmp = 999999 - start + philo->time->time2.tv_usec;
	return (tmp);
}

void	ft_sleep50(t_philo *philo)
{
	while (ft_get_time(philo, philo->time->time1.tv_usec) < 50000)
	{
		usleep(100);
		gettimeofday(&philo->time->time2, NULL);
	}
	gettimeofday(&philo->time->time1, NULL);
}
