/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/11 14:20:03 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_table table;

	ft_init_table(&table, av);
	ft_init_forks(&table);
	ft_init_philosophers(&table);

//	pthread_create(&data.philo.thread, NULL, ft_routine, &data);
	
	pthread_join(table.philos[0].thread, NULL);
	pthread_join(table.philos[1].thread, NULL);
	pthread_join(table.philos[2].thread, NULL);

/*	printf("philo/forks = %d\n", data.table.nb_philo);
	printf("to die = %d\n", data.table.to_die);
	printf("to eat = %d\n", data.table.to_eat);
	printf("to sleep = %d\n", data.table.to_sleep);*/
//	printf("%d\n", data.table.to_think);

	return (0);
}
