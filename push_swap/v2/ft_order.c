/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:14:17 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/08 18:15:26 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_order_sort(t_nb *pile, t_pile *obj)
{
	int		i;
	int		nb_values;
	int		res;
	void	*tmp;

	i = 1;
	nb_values = 0;
	res = 0;
	tmp = pile;
	obj->nb_arg = ft_check_pile(pile);
	obj->order = malloc(sizeof(int) * obj->nb_arg);
	while (pile && i < ft_check_min1(tmp))
	{
		pile = pile->next;
		i++;
	}
	i = pile->nb;
	pile = tmp;
	while (nb_values < obj->nb_arg && i < 2147483647)
	{
		if (ft_check_nb1(i, pile) == 0)
		{
			obj->order[nb_values] = i;
			nb_values++;
		}
		i++;
	}
	obj->order[nb_values] = i;
	ft_order_display(obj->nb_arg, obj);
	res = ft_get_med(obj->nb_arg, obj->order);
	ft_delete_tab(obj->nb_arg, obj->order);
	return (res);
}

int		ft_get_med(int nb, int *tab)
{
	int res;

	if (nb % 2 == 0)
		res = ((tab[nb / 2]) + (tab[(nb / 2) - 1])) / 2;
	else
		res = tab[nb / 2];
	return (res);
}
