/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 03:06:11 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 04:29:59 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_next(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 0;
	while (pile->next != tmp)
	{
		pile = pile->next;
		if (pile->nb <= nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_find_prev(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 1;
	while (pile->prev != tmp)
	{
		pile = pile->prev;
		if (pile->nb <= nb)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_next(t_data *obj, int nb)
{
	while (nb > 0)
	{
		ft_ra(obj);
		nb--;
	}
}

void	ft_move_prev(t_data *obj, int nb)
{
	while (nb > 0)
	{
		ft_rra(obj);
		nb--;
	}
}

void	ft_get_spotA(t_data *obj, int lim)
{
	if (ft_find_next(obj->pileA, lim) > ft_find_prev(obj->pileA, lim))
		ft_move_prev(obj, ft_find_prev(obj->pileA, lim));
	else
		ft_move_next(obj, ft_find_next(obj->pileA, lim));
}
