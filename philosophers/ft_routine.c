/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:18:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/18 14:14:31 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_print(t_philo *philo, char action)
{
	pthread_mutex_lock(&philo->arg->print);
	if (philo->arg->nb_life == philo->arg->nb_philo)
	{
		if (action == 'e')
			printf("%ldms philo%d is eating\n",
				ft_get_time(philo, philo->time->start), philo->id);
		else if (action == 's')
			printf("%ldms philo%d is sleeping\n",
				ft_get_time(philo, philo->time->start), philo->id);
		else if (action == 't')
			printf("%ldms philo%d is thinking\n",
				ft_get_time(philo, philo->time->start), philo->id);
		else if (action == 'd')
		{
			philo->arg->nb_life--;
			printf("%ldms philo%d died\n",
				ft_get_time(philo, philo->time->start), philo->id);
		}
		ft_print_forks(philo, action);
		pthread_mutex_unlock(&philo->arg->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->arg->print);
	return (-1);
}

int	ft_print_forks(t_philo *philo, char action)
{
	if (action == 'f')
	{
		printf("%ldms philo%d has taken forks\n",
			ft_get_time(philo, philo->time->start), philo->id);
		return (0);
	}
	return (-1);
}

void	*ft_routine(void *arg)
{
	t_philo	*tmp;
	int		res;

	tmp = (t_philo *)arg;
	if (tmp->id % 2 == 0 && tmp->last_meal == tmp->time->start)
		usleep(1);
	ft_grab_forks(tmp);
	res = ft_eat(tmp);
	if (res < 0)
		return (NULL);
	ft_drop_forks(tmp);
	res = ft_sleep(tmp);
	if (res < 0)
		return (NULL);
	res = ft_think(tmp);
	if (res < 0)
		return (NULL);
	return (NULL);
}

void	*ft_routine1(void *arg)
{
	t_philo	*tmp;
	int		nb_philo;

	tmp = arg;
	nb_philo = tmp->arg->nb_philo;
	while (nb_philo == tmp->arg->nb_life)
	{
		ft_routine(arg);
	}
	return (NULL);
}

void	ft_free_data(t_table *table)
{
	free(table->arg);
	free(table->philos);
	free(table->forks);
	free(table->time);
}
