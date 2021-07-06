/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:14:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/06 18:41:08 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_sort(t_pile *obj)
{
	int		i;
	int		nb_values;
	int		min;
	void	*tmp;

	i = 1;
	nb_values = 0;
	min = ft_check_min(obj);
	tmp = obj->pileA;
	obj->order = malloc(sizeof(char) * obj->nb_arg);
	while (obj->pileA->next && i < min)
	{
		obj->pileA = obj->pileA->next;
		i++;
	}
	i = obj->pileA->nb;
	obj->pileA = tmp;
	while (nb_values < obj->nb_arg && i < 2147483647)
	{
		if (ft_check_nb(i, obj) == 0)
		{
			obj->order[nb_values] = i;
			nb_values++;
		}
		i++;
	}
	ft_order_display(obj->nb_arg, obj);
}

int		ft_get_med(t_pile *obj)
{
	int res;

	if (obj->nb_arg % 2 == 0)
		res = ((obj->order[obj->nb_arg / 2]) + (obj->order[(obj->nb_arg / 2) - 1])) / 2;
	else
		res = obj->order[obj->nb_arg / 2];
	printf("%d\n", res);
	return (res);
}
