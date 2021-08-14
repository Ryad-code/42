/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/14 15:19:55 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	(void)ac;
	t_table 		table;

	ft_start(&table);
//.....................................................Time
//.....................................................Initialisations
	ft_init_table(&table, av);
	ft_init_forks(&table);
	ft_init_philosophers(&table);
//..................................................................
//.....................................................Fin des threads	
	pthread_join(table.philos[0].thread, NULL);
	pthread_join(table.philos[1].thread, NULL);
//	pthread_join(table.philos[2].thread, NULL);
//	pthread_join(table.philos[3].thread, NULL);
//	pthread_join(table.philos[4].thread, NULL);
//	pthread_join(table.philos[5].thread, NULL);
//.................................................................
//	printf("lm = %ld\n", __LONG_MAX__);

	return (0);
}
