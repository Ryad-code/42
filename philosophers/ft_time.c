/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:59:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/13 12:59:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_table *table)
{
	gettimeofday(&table->time2, NULL);
	printf("%d microseconds\n", table->time2.tv_usec - table->time1.tv_usec);
	table->time1.tv_usec = table->time2.tv_usec;
	while (table->time2.tv_usec - table->time1.tv_usec < 50000)
	{
		usleep(1000);
		printf("t2 = %d, t1 = %d, %d microseconds\n", table->time2.tv_usec, table->time1.tv_usec, table->time2.tv_usec - table->time1.tv_usec);
		gettimeofday(&table->time2, NULL);
	}
	printf("%d microseconds\n", table->time2.tv_usec - table->time1.tv_usec);
}
