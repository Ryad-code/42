/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:52:33 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 02:52:37 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data *obj)
{
	ft_swap(&obj->pileA);
	obj->nb_op++;
	write(1, "sa\n", 3);
}

void	ft_sb(t_data *obj)
{
	ft_swap(&obj->pileB);
	obj->nb_op++;
	write(1, "sb\n", 3);
}

void	ft_ss(t_data *obj)
{
	ft_swap(&obj->pileA);
	ft_swap(&obj->pileB);
	obj->nb_op++;
	write(1, "ss\n", 3);
}

void	ft_pa(t_data *obj)
{
	ft_push(&obj->pileB, &obj->pileA);
	obj->nb_op++;
	write(1, "pa\n", 3);
}
