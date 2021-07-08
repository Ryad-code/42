/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:05:15 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/08 15:11:56 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_get_sort(t_pile *obj)
{
	if (obj->nb_arg == 2)
		ft_sort_2(obj->pileA, obj);
	else if (obj->nb_arg == 3)
		ft_sort_3(obj);
	else if (obj->nb_arg == 4)
		ft_sort_4(obj);
	else if (obj->nb_arg == 5)
		ft_sort_5(obj);
	else if (obj->nb_arg == 6)
		ft_sort_6(obj);
	else if (obj->nb_arg > 6 && obj->nb_arg < 10)
		ft_default_sort(obj);
	else if (obj->nb_arg >= 10)
		ft_quick_sort(obj);
}

void	ft_push_min(int nb_args, t_pile *obj)
{
	int	i;
	int	min;

	i = 0;
	min = ft_check_min(obj);
	if (min <= nb_args / 2)
	{
		while (i < min - 1)
		{
			ft_ra(obj);
			i++;
		}
	}
	else if (min > nb_args / 2)
	{
		while (i < (nb_args - min) + 1)
		{
			ft_rra(obj);
			i++;
		}
	}
	ft_pb(obj);
}

void	ft_sort_2(t_nb *pile, t_pile *obj)
{
	void	*tmp;
	int		nb;

	tmp = pile;
	nb =  pile->nb;
	pile = pile->next;
	if (nb > pile->nb)
	{
		pile = tmp;
		ft_sa(obj);
	}
	pile = tmp;
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
	ft_push_min(obj->nb_arg, obj);
	ft_sort_3(obj);
	ft_pa(obj);
}

void	ft_sort_5(t_pile *obj)
{
	ft_push_min(obj->nb_arg, obj);
	ft_push_min(obj->nb_arg - 1, obj);
	ft_sort_3(obj);
	ft_sort_2(obj->pileB, obj);
	ft_pa(obj);
	ft_pa(obj);
}

void	ft_sort_6(t_pile *obj)
{
		ft_push_min(obj->nb_arg, obj);
		ft_push_min(obj->nb_arg - 1, obj);
		ft_push_min(obj->nb_arg - 2, obj);
		ft_sort_3(obj);
		ft_pa(obj);
		ft_pa(obj);
		ft_pa(obj);

}

void	ft_default_sort(t_pile *obj)
{
	int	mid;
	int	i;
	int	j;
	int	tmp;

	tmp =  obj->nb_arg;
	j = 0;
	if (obj->nb_arg % 2 == 0)
		mid = obj->nb_arg / 2;
	else
		mid = (obj->nb_arg / 2) + 1;
	while (j < obj->nb_arg && ft_check_order(obj->pileA) != 0)
	{
		i = 0;
		ft_push_min(tmp, obj);
		tmp--;
		j++;
	}
	while (j > 0)
	{
		ft_pa(obj);
		j--;
	}
}
