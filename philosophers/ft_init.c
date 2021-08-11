/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:58:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/11 14:40:20 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_table(t_table *table, char **av)
{
	if (av[1] && av[2] && av[3] && av[4])
	{
		table->nb_philo = ft_atoi(av[1]);
		table->to_die = ft_atoi(av[2]);
		table->to_eat = ft_atoi(av[3]);
		table->to_sleep = ft_atoi(av[4]);
		return (0);
	}
	else
		return (-1);
}

void	ft_init_philosophers(t_table *table)
{
	int i;

	i = 1;
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	table->philos[0].id =  1;
	pthread_create(&table->philos[0].thread, NULL, ft_routine, &table->philos[0]);
	table->philos[0].r_fork = &table->forks[0];
	table->philos[0].l_fork = &table->forks[table->nb_philo];
	while (i < table->nb_philo)
	{
		table->philos[i].id = i + 1;
		pthread_create(&table->philos[i].thread, NULL, ft_routine, &table->philos[i]);
		table->philos[i].r_fork = &table->forks[i];
		table->philos[i].l_fork = &table->forks[i - 1];
		i++;
	}
}

void	ft_init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}
