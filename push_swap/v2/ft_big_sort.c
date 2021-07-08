/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:46:18 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/08 15:22:43 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_pile *obj)
{
	int		i;
	int		j;
	int		med;
	void	*tmp;

	i = 0;
	j = 0;
	med = ft_order_sort(obj->pileA, obj);
	tmp = obj->pileA;
	while (i < obj->nb_arg / 2 && j < obj->nb_arg)
	{
		if (obj->pileA->nb <= med)
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
