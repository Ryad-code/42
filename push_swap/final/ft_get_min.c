/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:42:45 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/04 11:27:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_check_pile(t_pile *pile)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = pile;
	while (pile->next != tmp)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

t_pile	*ft_get_minA(t_pile *pile)
{
	void	*tmp;
	t_pile	*res1;
	int		res;

	tmp = pile;
	res = pile->next->nb;
	res1 = pile->next;
	pile = pile->next;
	while (pile->next != tmp)
	{
		if (res > pile->next->nb)
		{
			res = pile->next->nb;
			res1 = pile->next;
		}
		pile = pile->next;
	}
	return (res1);
}

int	ft_find_minA(t_pile *pile)
{
	void	*tmp1;
	t_pile	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	tmp1 = pile;
	tmp = ft_get_minA(pile);
	i = 0;
	j = 1;
	while (pile->next != tmp)
	{
		i++;
		pile = pile->next;
	}
	pile = tmp1;
	while (pile->prev != tmp)
	{
		j++;
		pile = pile->prev;
	}
	if (i < j)
		return (i);
	else
		return (-j);
}

void	ft_push_minA(t_data *obj)
{
	int		res;

	res = ft_find_minA(obj->pileA);
	if (res > 0)
	{
		while (res > 0)
		{
			ft_ra(obj);
			res--;
		}
		ft_pb(obj);
	}
	else
	{
		while (res < 0)
		{
			ft_rra(obj);
			res++;
		}
		ft_pb(obj);
	}
}
