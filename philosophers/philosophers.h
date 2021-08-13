/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:01:29 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/13 15:09:03 by mlaouedj         ###   ########.fr       */
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

typedef struct		s_arg
{
	int				nb_philo;
	int				to_die;
	int				to_eat;
	int	 			to_sleep;
}					t_arg;

typedef struct		s_philo
{
	int				id;
	t_arg			*arg;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t *l_fork;
}					t_philo;

typedef struct s_table
{
	struct  timeval time1;
	struct	timeval time2;
	t_arg			*arg;
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
//........................................//Time
int		ft_get_time(t_table *table);
void	ft_sleep(t_table *table);

#endif
