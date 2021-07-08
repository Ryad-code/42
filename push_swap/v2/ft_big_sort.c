/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:46:18 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/08 19:06:11 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sortA(t_pile *obj)
{
	int		i;
	int		j;
	int		med;
	void	*tmp;

	i = 0;
	j = 0;
	med = ft_order_sort(obj->pileA, obj);
	printf("medA = %d\n\n", med);
	tmp = obj->pileA;
	while (i < ((obj->nb_arg / 2) + (obj->nb_arg % 2)) && j < obj->nb_arg)
	{
		if (obj->pileA->nb < med)
		{
			ft_pb(obj);
			i++;
		}
		else 
			ft_ra(obj);
		j++;
	}
	if (obj->pileA->nb < med)
		ft_pb(obj);
}

void	ft_quick_sortB(t_pile *obj)
{
	int		i;
	int		j;
	int		med;
	void	*tmp;

	i = 0;
	j = 0;
	med = ft_order_sort(obj->pileB, obj);
	printf("medB = %d\n\n", med);
	tmp = obj->pileB;
	while (i < (obj->nb_arg / 2) && j < obj->nb_arg)

	{
		if (obj->pileB->nb > med)
		{
			ft_pa(obj);
			i++;
		}
		else
			ft_rb(obj);
		j++;
	}
	if (obj->pileB->nb > med)
		ft_pa(obj);
}

void	ft_quick_sort(t_pile *obj)
{
	int i;

	i = 1;
//	while (ft_check_order(obj->pileA) != 0 || ft_check_order(obj->pileB) != 0)
	while (i < 10)
	{
		if (i % 2)
			ft_quick_sortA(obj);
		else
			ft_quick_sortB(obj);

		ft_display(obj->pileA);
		ft_display(obj->pileB);
		i++;
	}
}
