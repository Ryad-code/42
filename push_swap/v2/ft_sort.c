/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:05:15 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/05 15:21:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_get_sort(int ac, t_pile *obj)
{
	int	nb_args;

	nb_args = ac - 1;
	if (nb_args == 2)
		ft_sort_2(obj);
	else if (nb_args == 3)
		ft_sort_3(obj);
	else if (nb_args == 4)
		ft_sort_4(obj);
	else
		ft_default_sort(ac - 1, obj);
}

void	ft_sort_2(t_pile *obj)
{
	void	*tmp;
	int		nb;

	tmp = obj->pileA;
	nb =  obj->pileA->nb;
	obj->pileA = obj->pileA->next;
	if (nb > obj->pileA->nb)
	{
		obj->pileA = tmp;
		ft_sa(obj);
	}
	obj->pileA = tmp;
}

void	ft_sort_3(t_pile *obj)
{
	int	order;

	order = ft_check_pile_3(obj);
	if (order == 2)
	{
		ft_sa(obj);
		ft_ra(obj);
	}
	else if (order == 3)
		ft_sa(obj);
	else if (order == 4)
		ft_rra(obj);
	else if (order == 5)
		ft_ra(obj);
	else if (order == 6)
	{
		ft_ra(obj);
		ft_sa(obj);
	}
}

void	ft_sort_4(t_pile *obj)
{
	int i;
	int	arg_min;

	i = 1;
	arg_min = ft_check_pile_4(obj);
	if (arg_min < 4)
	{
		while (i < arg_min)
		{
			ft_ra(obj);
			i++;
		}
		ft_pb(obj);
	}
	else if (arg_min == 4)
	{
		ft_rra(obj);
		ft_pb(obj);
	}
	ft_sort_3(obj);
	ft_pa(obj);
}

void	ft_default_sort(int nb_args, t_pile *obj)
{
	int	mid;
	int	i;
	int	j;
	int	min;
	int	tmp;

	tmp =  nb_args;
	j = 0;
	if (nb_args % 2 == 0)
		mid = nb_args / 2;
	else
		mid = (nb_args / 2) + 1;
	while (j < tmp)
	{
		i = 0;
		min = ft_check_pile_4(obj);
		if (min <= mid)
		{
			while (i < min - 1)
			{
				ft_ra(obj);
				i++;
			}
		}
		else if (min > mid)
		{
			while (i < (nb_args - min) + 1)
			{
				ft_rra(obj);
				i++;
			}
		}
		ft_pb(obj);
		nb_args--;
		j++;
//		ft_display(obj->pileA);
//		ft_display(obj->pileB);
	}
	while (j > 0)
	{
		ft_pa(obj);
		j--;
	}
}
