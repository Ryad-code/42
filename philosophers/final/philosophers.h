/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:01:29 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/19 11:13:22 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				state;
}					t_fork;

typedef struct s_time
{
	long			start;
	struct timeval	time1;
	struct timeval	time2;
}					t_time;

typedef struct s_arg
{
	int				nb_philo;
	int				nb_life;
	int				nb_meal;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	pthread_mutex_t	print;
}					t_arg;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				nb_meal;
	t_time			*time;
	t_arg			*arg;
	pthread_t		thread;
	t_fork			*r_fork;
	t_fork			*l_fork;
}					t_philo;

typedef struct s_table
{
	t_time		*time;	
	t_arg		*arg;
	t_philo		*philos;
	t_fork		*forks;	
}				t_table;

long	ft_atoi(char *str);
int		ft_init_table(t_table *table, char **av);
void	ft_init_philosophers(t_table *table);
void	ft_init_forks(t_table *table);
void	ft_thread_join(t_table *table);
void	ft_grab_forks(t_philo *philo);
void	ft_drop_forks(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		ft_think(t_philo *philo);
int		ft_print(t_philo *philo, char action);
int		ft_print_forks(t_philo *philo, char action);
void	*ft_routine(void *arg);
void	*ft_routine1(void *arg);
void	ft_start(t_table *table);
long	ft_get_time(t_philo *philo, long start);
long	ft_get_time1(t_philo *philo);
void	ft_sleep1ms(t_philo *philo);
int		ft_usleep(t_philo *philo, int duration);
void	ft_free_data(t_table *table);
int		ft_is_digit(char c);
int		ft_is_nb(char *str);
int		ft_arg(int ac, char **av);
void	ft_one_philo(char **av);

#endif
