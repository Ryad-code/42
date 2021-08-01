/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:37:49 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 02:40:38 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_root(t_pile **pile)
{
	t_pile	*obj;

	obj = malloc(sizeof(t_pile));
	if (obj == NULL)
		return (-1);
	obj->nb = 0;
	obj->prev = obj;
	obj->next = obj;
	*pile = obj;
	return (0);
}

int	ft_create(t_pile **pile, int nb)
{
	t_pile	*obj;

	obj = malloc(sizeof(t_pile));
	if (obj == NULL)
		return (-1);
	obj->nb = nb;
	obj->prev = *pile;
	obj->next = (*pile)->next;
	(*pile)->next = obj;
	obj->next->prev = obj;
	return (0);
}

int	ft_delete(t_pile *pile)
{
	pile->prev->next = pile->next;
	pile->next->prev = pile->prev;
	free(pile);
	return (0);
}

void	ft_init_pileA(t_data *obj, int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		ft_create(&obj->pileA, ft_atoi(av[i]));
		i--;
	}
}

int	ft_check_pile(t_pile *pile)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = pile;
	while (pile->next != tmp)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}
