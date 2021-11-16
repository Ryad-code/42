/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/01 18:17:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ft_arg(ac, av) < 0)
	{
		printf("Error");
		return (-1);
	}
	if (ft_atoi(av[1]) == 1)
	{
		ft_one_philo(av);
		return (0);
	}
	ft_start(&table);
	if (ft_init_table(&table, av) > 0)
		return (-1);
	if (ft_init_forks(&table) > 0)
		return (-1);
	if (ft_init_philosophers(&table) > 0)
		return (-1);
	ft_thread_join(&table);
	ft_free_data(&table);
	return (0);
}
