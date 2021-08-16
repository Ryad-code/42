/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/16 12:21:29 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	(void)ac;
	t_table 		table;

	ft_start(&table);
//.....................................................Initialisations
	ft_init_table(&table, av);
	ft_init_forks(&table);
	ft_init_philosophers(&table);
//.....................................................Fin des threads
	ft_thread_join(&table);
//.....................................................
	return (0);
}
