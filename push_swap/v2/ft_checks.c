/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:06:07 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/02 18:35:08 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_pile(t_nb *pile)
{
	int	i;

	i = 1;
	if (!pile)
		return (-1);
	while (pile->next)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

int	ft_check_args(int ac, t_pile *obj)
{
	if (ac < 2)
		return (-1);
	return (0);
}

int	ft_check_pile_3(t_pile *obj)
{
	void	*tmp;
	int		i;
	int		tab[3];

	tmp = obj->pileA;
	i = 0;
	while (obj->pileA->next)
	{
		tab[i] = obj->pileA->nb;
		obj->pileA = obj->pileA->next;
		i++;
	}
	tab[i] = obj->pileA->nb;
	obj->pileA = tmp;
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

int	ft_check_pile_4(t_pile *obj)
{
	void	*tmp;
	int		i;
	int		res;
	int		nb;

	tmp = obj->pileA;
	i  = 1;
	res = 1;
	nb = obj->pileA->nb;
	while (obj->pileA->next)
	{
		obj->pileA = obj->pileA->next;
		if (obj->pileA->nb < nb)
		{
			nb = obj->pileA->nb;
			res = i + 1;
		}
		i++;
	}
	obj->pileA = tmp;
	return (res);
}
