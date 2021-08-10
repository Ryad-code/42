/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 16:20:49 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_data data;

	ft_init_table(&data, av);
	ft_init_forks(&data);
	data.philo.id = 1;
	pthread_mutex_init(&data.philo.mutex, NULL);

	pthread_create(&data.philo.thread, NULL, ft_eat, &data);
	pthread_create(&data.philo.thread, NULL, ft_sleep, &data);
//	pthread_create(&data.philo.thread, NULL, ft_think, &data);
	pthread_join(data.philo.thread, NULL);
	pthread_join(data.philo.thread, NULL);

/*	printf("philo/forks = %d\n", data.table.nb_philo);
	printf("to die = %d\n", data.table.to_die);
	printf("to eat = %d\n", data.table.to_eat);
	printf("to sleep = %d\n", data.table.to_sleep);*/
//	printf("%d\n", data.table.to_think);

	ft_display_forks(data);
	return (0);
}
