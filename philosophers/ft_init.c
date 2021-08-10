/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:58:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 15:16:06 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_table(t_data *data, char **av)
{
	data->table.nb_philo = ft_atoi(av[1]);
	data->table.to_die = ft_atoi(av[2]);
	data->table.to_eat = ft_atoi(av[3]);
	data->table.to_sleep = ft_atoi(av[4]);
//	data->table.to_think = ft_atoi(av[5]);
}

void	ft_init_forks(t_data *data)
{
	int i;

	i = 0;
	data->table.fork_tab = malloc(sizeof(int) * data->table.nb_philo);
	while (i < data->table.nb_philo)
	{
		data->table.fork_tab[i] = 1;
		i++;
	}
}

void	ft_display_forks(t_data data)
{
	int i;

	i = 0;
	while (i < data.table.nb_philo)
	{
		printf(" f%d = %d |", i, data.table.fork_tab[i]);
		i++;
	}
	printf("\n");
}
