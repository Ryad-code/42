/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:59:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/14 15:33:33 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_start(t_table *table)
{
	table->time = malloc(sizeof(t_time));
	gettimeofday(&table->time->time1, NULL);
//	table->time->start_s = table->time->time1.tv_sec;
//	table->time->start_ms = table->time->time1.tv_usec;
	table->time->start = (table->time->time1.tv_sec * 1000)	+ (table->time->time1.tv_usec / 1000);
	printf("s= %ld, us = %d, start = %ld\n", table->time->time1.tv_sec, table->time->time1.tv_usec, table->time->start);
	printf("0 ms--->START\n");
}

long	ft_get_time1(t_philo *philo, long start)
{
	long res;
	
	gettimeofday(&philo->time->time2, NULL);
	res = (philo->time->time2.tv_sec * 1000) + (philo->time->time2.tv_usec / 1000);
//	printf("res = %ld, start = %ld\n", res, start);
	return (res - start);
}
/*
int		ft_get_time(t_philo *philo, int start)
{
	long tmp;

	tmp = 0;
	gettimeofday(&philo->time->time2, NULL);
	if (philo->time->time2.tv_usec >= start)
		tmp = philo->time->time2.tv_usec - start;
	else
	{
		tmp = 999999 - start + philo->time->time2.tv_usec;
//		printf("t1=%d, t2=%d, res = %ld\n", start, philo->time->time2.tv_usec, tmp);
	}
	return (tmp);
}*/

void	ft_sleep5ms(t_philo *philo)
{
	long res;

	res = (philo->time->time1.tv_sec * 1000) + (philo->time->time1.tv_usec / 1000);
	while (ft_get_time1(philo, res) < 1)
	{
		usleep(50);
		gettimeofday(&philo->time->time2, NULL);
	}
	printf("res = %ld\n", ft_get_time1(philo, philo->time->time1.tv_usec));
	gettimeofday(&philo->time->time1, NULL);
}

void	ft_sleep(t_philo *philo, int duration)
{
	int i;
	int	tmp;

	i = 0;
	tmp = duration;
	while (i < tmp)
	{
		ft_sleep5ms(philo);
		i++;
	}
}
