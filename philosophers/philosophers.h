/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:01:29 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 12:53:45 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct s_table
{
	int		nb_philo;
	int		to_eat;
	int		to_sleep;
	int		to_think;
	int		to_die;
}				t_table;

typedef struct	s_philo
{
	int			id;
	pthread_t	thread;
	bool		is_eating;
	bool		is_sleeping;
	bool		is_thinking;
}				t_philo;

void    *ft_eat(void *arg);
void    *ft_sleep(void *arg);
void    *ft_think(void *arg);

#endif
