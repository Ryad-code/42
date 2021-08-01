/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:42:45 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 04:29:45 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	t_pile	*tmp;
	int		res;

	tmp = ft_get_minA(obj->pileA);
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

/*void	ft_push_minB(t_data *obj)
{
	t_pile	*tmp;
	int		res;

	tmp = ft_get_min(obj->pileB);
	res = ft_find_min(obj->pileB);
	if (res > 0)
	{
		while (res > 0)
		{
			ft_rb(obj);
			res--;
		}
		ft_pa(obj);
	}
	else
	{
		while (res < 0)
		{
			ft_rrb(obj);
			res++;
		}
		ft_pa(obj);
	}
}*/
