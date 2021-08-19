/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/19 10:52:37 by mlaouedj         ###   ########.fr       */
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
	ft_start(&table);
	ft_init_table(&table, av);
	ft_init_forks(&table);
	ft_init_philosophers(&table);
	ft_thread_join(&table);
	ft_free_data(&table);
	return (0);
}
