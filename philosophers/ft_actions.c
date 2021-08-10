/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:43:40 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/10 12:56:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_eat(void	*arg)
{
	t_table *tmp;

	tmp = (t_table*)arg;
	sleep(tmp->to_eat);
//	tmp->is_eating = TRUE;
	printf("is eating");
	return (NULL);
}

void    *ft_sleep(void *arg)
{
	return (NULL);
}

void    *ft_think(void *arg)
{
	return (NULL);
}

