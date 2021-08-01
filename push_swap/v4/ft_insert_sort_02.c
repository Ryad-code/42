/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 04:14:08 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 04:30:08 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_first_chunk(t_data *obj, int lim, int nb_val)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	ft_get_spotA(obj, lim);
	ft_pb(obj);
	ft_get_spotA(obj, lim);
	ft_pb(obj);
	if (obj->pileB->next->nb < obj->pileB->prev->nb)
		ft_sb(obj);
	obj->max = obj->pileB->next->nb;
	obj->min = obj->pileB->prev->nb;
	while (i < nb_val - 2)
	{
		ft_get_spotA(obj, lim);
		ft_get_spotB(obj, obj->pileA->next->nb);
		ft_pb(obj);
		i++;
	}
}

void	ft_push_chunk(t_data *obj, int lim, int nb_val)
{
	int	i;

	i = 0;
	while (i < nb_val)
	{
		ft_get_spotA(obj, lim);
		ft_get_spotB(obj, obj->pileA->next->nb);
		ft_pb(obj);
		i++;
	}
}

int	ft_find_min(t_pile *pile)
{
	void	*tmp;
	int		i;
	int		res;
	int		res1;

	tmp = pile;
	i = 1;
	res = pile->next->nb;
	res1 = 1;
	pile = pile->next;
	while (pile->next != tmp)
	{
		if (res > pile->next->nb)
		{
			res = pile->next->nb;
			res1 = i + 1;
		}
		pile = pile->next;
		i++;
	}
	return (res1);
}

void	ft_push_back(t_data *obj)
{
	int	i;
	int	spot;
	int	len;

	i = 0;
	spot = ft_find_min(obj->pileB);
	len = ft_check_pile(obj->pileB);
	ft_choose_path(obj, spot);
	while (i < len)
	{
		ft_pa(obj);
		i++;
	}
}

void	ft_insert_sort(t_data *obj)
{
	int	i;
	int	nb_val;
	int	chunk_nb;
	int	chunk_len;
	int	rest;

	i = 0;
	nb_val = ft_check_pile(obj->pileA);
	chunk_nb = ft_get_chunk_nb(nb_val);
	chunk_len = ft_get_chunk_len(nb_val);
	rest = ft_get_rest(nb_val);
	ft_push_first_chunk(obj, obj->order[chunk_len - 1], chunk_len);
	while (i < chunk_nb - 1)
	{
		ft_push_chunk(obj, obj->order[(chunk_len * (i + 2)) - 1], chunk_len);
		i++;
	}
	if (rest != 0)
		ft_get_sort(obj);
	ft_push_back(obj);
}
