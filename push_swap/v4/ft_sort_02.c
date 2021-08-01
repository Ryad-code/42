/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:56:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 03:00:43 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_data *obj)
{
	if (obj->pileA->next->nb > obj->pileA->next->next->nb)
		ft_sa(obj);
}

void	ft_sort_3(t_data *obj)
{
	int	order;

	order = ft_check_sort3(obj->pileA);
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

void	ft_sort_4(t_data *obj)
{
	ft_push_minA(obj);
	ft_sort_3(obj);
	ft_pa(obj);
}

void	ft_sort_5(t_data *obj)
{
	ft_push_minA(obj);
	ft_push_minA(obj);
	ft_sort_3(obj);
	ft_pa(obj);
	ft_pa(obj);
}

void	ft_sort_6(t_data *obj)
{
	ft_push_minA(obj);
	ft_push_minA(obj);
	ft_push_minA(obj);
	ft_sort_3(obj);
	ft_pa(obj);
	ft_pa(obj);
	ft_pa(obj);
}
