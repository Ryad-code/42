/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:58:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/18 11:46:01 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_table(t_table *table, char **av)
{
	table->arg = malloc(sizeof(t_arg));
	if (av[1] && av[2] && av[3] && av[4])
	{
		table->arg->nb_philo = ft_atoi(av[1]);
		table->arg->nb_life = table->arg->nb_philo;
		table->arg->to_die = ft_atoi(av[2]);
		table->arg->to_eat = ft_atoi(av[3]);
		table->arg->to_sleep = ft_atoi(av[4]);
		return (0);
	}
	else
		return (-1);
}

void	ft_init_philo1(t_table *table)
{
	table->philos[0].id = 1;
	table->philos[0].last_meal = table->time->start;
	table->philos[0].arg = table->arg;
	table->philos[0].time = table->time;
	table->philos[0].r_fork = &table->forks[0];
	table->philos[0].l_fork = &table->forks[table->arg->nb_philo - 1];
	pthread_create(&table->philos[0].thread, NULL, ft_routine1, &table->philos[0]);
}

void	ft_init_philosophers(t_table *table)
{
	int	i;

	i = 1;
	table->philos = malloc(sizeof(t_philo) * table->arg->nb_philo);
	ft_init_philo1(table);
	while (i < table->arg->nb_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_meal = table->time->start;
		table->philos[i].arg = table->arg;
		table->philos[i].time = table->time;
		table->philos[i].r_fork = &table->forks[i];
		table->philos[i].l_fork = &table->forks[i - 1];
		pthread_create(&table->philos[i].thread, NULL, ft_routine1, &table->philos[i]);
		i++;
	}
}

void	ft_init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(t_fork) * table->arg->nb_philo);
	while (i < table->arg->nb_philo)
	{
		pthread_mutex_init(&table->forks[i].mutex, NULL);
		table->forks[i].state = 0;
		i++;
	}
}

void	ft_thread_join(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->arg->nb_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
