/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:59:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/13 15:16:20 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_get_time(t_table *table)
{
	int tmp;

	tmp = 0;
	gettimeofday(&table->time2, NULL);
	if (table->time2.tv_usec >= table->time1.tv_usec)
		tmp = table->time2.tv_usec - table->time1.tv_usec;
	else
		tmp = 999999 - table->time1.tv_usec + table->time2.tv_usec;
	return (tmp);
}

void	ft_sleep(t_table *table)
{
	while (ft_get_time(table) < 50000)
	{
		usleep(100);
		gettimeofday(&table->time2, NULL);
	}
	printf("%d microseconds\n", ft_get_time(table) / 1000);
	table->time1.tv_usec = table->time2.tv_usec;
}
