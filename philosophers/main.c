/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 13:01:45 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	struct timeval	time;
	long	tmp;
	t_table	table;
	pthread_t t1;

	table.to_eat = 2;
	gettimeofday(&time, NULL);
	tmp = time.tv_sec;
	gettimeofday(&time, NULL);
	printf("seconds = %ld\n", tmp - time.tv_sec);
	pthread_create(&t1, NULL, ft_eat, &table);

	pthread_join(t1, NULL);
	return (0);
}
