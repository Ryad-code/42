/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:59:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/17 16:47:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_start(t_table *table)
{
	table->time = malloc(sizeof(t_time));
	gettimeofday(&table->time->time1, NULL);
	table->time->start = (table->time->time1.tv_sec * 1000)
		+ (table->time->time1.tv_usec / 1000);
	printf("0 ms--->START\n");
}

long	ft_get_time(t_philo *philo, long start)
{
	long	res;

	gettimeofday(&philo->time->time2, NULL);
	res = (philo->time->time2.tv_sec * 1000)
		+ (philo->time->time2.tv_usec / 1000);
	return (res - start);
}

long	ft_get_time1(t_philo *philo)
{
	long	res;

	gettimeofday(&philo->time->time2, NULL);
	res = (philo->time->time2.tv_sec * 1000)
		+ (philo->time->time2.tv_usec / 1000);
	return (res);
}

void	ft_sleep1ms(t_philo *philo)
{
	long	res;

	res = (philo->time->time1.tv_sec * 1000)
		+ (philo->time->time1.tv_usec / 1000);
	while (ft_get_time(philo, res) < 1)
	{
		usleep(50);
		gettimeofday(&philo->time->time2, NULL);
	}
	gettimeofday(&philo->time->time1, NULL);
}

int	ft_usleep(t_philo *philo, int duration)
{
	int	i;

	i = 0;
	while (i < duration)
	{
		if (ft_get_time(philo, philo->last_meal) > philo->arg->to_die)
			return (-1);
		ft_sleep1ms(philo);
		i++;
	}
	return (0);
}
