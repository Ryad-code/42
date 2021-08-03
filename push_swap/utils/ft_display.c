/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:41:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 04:29:33 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_display_prev(t_pile *pile)
{
	void	*tmp;

	tmp = pile;
	if (pile->prev == tmp)
		printf("VIDE\n");
	while (pile->prev != tmp)
	{
		pile = pile->prev;
		printf("|%3d |\n", pile->nb);
	}
}

void	ft_display_next(t_pile *pile)
{
	void	*tmp;

	tmp = pile;
	if (pile->prev == tmp)
		printf("VIDE\n");
	while (pile->next != tmp)
	{
		pile = pile->next;
		printf("|%3d |\n", pile->nb);
	}
}

void	ft_display_order(t_data *obj, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		printf(" %d |", obj->order[i]);
		i++;
	}
	printf("\n");
}

void	ft_display(t_data *obj)
{
	printf("Pile_A :\n");
	ft_display_next(obj->pileA);
	printf("\nPile_B :\n");
	ft_display_next(obj->pileB);
	printf("------------------------\n");
}
