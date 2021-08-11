/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:01:29 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/11 12:37:39 by mlaouedj         ###   ########.fr       */
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

typedef struct		s_philo
{
	int				id;
	pthread_t		thread;
}					t_philo;

typedef struct s_table
{
	int				nb_philo;
	int             to_die;
	int				to_eat;
	int				to_sleep;
	t_philo         *philos;
	pthread_mutex_t *forks;
}				t_table;

//.........................................//Utils
long	ft_atoi(char *str);
//.........................................//Init
int		ft_init_table(t_table *table, char **av);
void	ft_init_philosophers(t_table *table);
void	ft_init_forks(t_table *table);
//.........................................//Actions
void    *ft_routine(void *arg);

#endif
