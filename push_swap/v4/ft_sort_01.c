/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:59:37 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/03 02:03:03 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_get_sort(t_data *obj)
{
	int	nb_val;

	nb_val = ft_check_pile(obj->pileA);
	if (nb_val == 2)
		ft_sort_2(obj);
	else if (nb_val == 3)
		ft_sort_3(obj);
	else if (nb_val == 4)
		ft_sort_4(obj);
	else if (nb_val == 5)
		ft_sort_5(obj);
	else if (nb_val == 6)
		ft_sort_6(obj);
	else if (nb_val > 6 && nb_val < 50)
		ft_default_sort(obj);
	else if (nb_val >= 50)
		ft_insert_sort(obj);
}

int	ft_check_sort3(t_pile *pile)
{
	int		i;
	int		tab[3];

	i = 0;
	while (i < 3)
	{
		pile = pile->next;
		tab[i] = pile->nb;
		i++;
	}
	if (tab[0] < tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		return (1);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
		return (2);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		return (3);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		return (4);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		return (5);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		return (6);
	return (0);
}

void	ft_default_sort(t_data *obj)
{
	int	nb_val;
	int	i;

	nb_val = ft_check_pile(obj->pileA);
	i = nb_val;
	while (nb_val > 0)
	{
		ft_push_minA(obj);
		nb_val--;
	}
	while (nb_val < i)
	{
		ft_pa(obj);
		nb_val++;
	}
}
