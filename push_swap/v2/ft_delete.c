/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:38:09 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/08 14:47:29 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_tab(int nb, int *tab)
{
	int	i;

	i = 0;
	while (i < nb && tab)
	{
		tab[i] = 0;
		i++;
	}
	free(tab);
}

void	ft_delete_pile(int nb, t_nb **pile)
{
	int	i;

	i = 0;
	while (i < nb && pile)
	{
		ft_delete(pile);
		i++;
	}
}

