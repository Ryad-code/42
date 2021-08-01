/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 03:08:27 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 03:09:20 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_spot_in(t_pile *pile)
{
	void	*tmp;
	int		res;
	int		res1;
	int		i;

	tmp = pile;
	res = pile->next->nb;
	res1 = 1;
	i = 1;
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

int	ft_spot_out(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 1;
	while (pile->next != tmp)
	{
		pile = pile->next;
		if (nb < pile->nb && nb > pile->next->nb)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_get_spotB(t_data *obj, int nb)
{
	int	spot;
	int	len;

	spot = ft_spot_in(obj->pileB);
	len = ft_check_pile(obj->pileB);
	if (nb > obj->max || nb < obj->min)
	{
		spot = ft_spot_in(obj->pileB);
		ft_choose_path(obj, spot);
	}
	else
	{
		spot = ft_spot_out(obj->pileB, obj->pileA->next->nb);
		ft_choose_path(obj, spot);
	}
	if (nb > obj->max)
		obj->max = nb;
	else if (nb < obj->min)
		obj->min = nb;
}

void	ft_choose_path(t_data *obj, int spot)
{
	int	len;

	len = ft_check_pile(obj->pileB);
	if (spot > len / 2)
	{
		while (len - spot > 0)
		{
			ft_rrb(obj);
			spot++;
		}
	}
	else
	{
		while (spot > 0)
		{
			ft_rb(obj);
			spot--;
		}
	}
}
