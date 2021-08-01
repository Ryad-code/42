/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:45:14 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 02:45:16 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_pile **from, t_pile **to)
{
	int	nb;

	if (ft_check_pile(*from) > 0)
	{	
		nb = (*from)->next->nb;
		ft_delete((*from)->next);
		ft_create(to, nb);
	}
}

void	ft_swap(t_pile **pile)
{
	int	nb;

	if (ft_check_pile(*pile) > 1)
	{
		nb = (*pile)->next->next->nb;
		(*pile)->next->next->nb = (*pile)->next->nb;
		(*pile)->next->nb = nb;
	}
}

void	ft_rotate(t_pile **pile)
{
	if (ft_check_pile(*pile) > 1)
	{
		(*pile)->nb = (*pile)->next->nb;
		(*pile)->next->nb = 0;
		*pile = (*pile)->next;
	}
}

void	ft_r_rotate(t_pile **pile)
{
	if (ft_check_pile(*pile) > 1)
	{
		(*pile)->nb = (*pile)->prev->nb;
		(*pile)->prev->nb = 0;
		*pile = (*pile)->prev;
	}
}
