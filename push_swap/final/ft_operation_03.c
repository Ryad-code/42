/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:48:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 04:31:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rra(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	obj->nb_op++;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_data *obj)
{
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rrr\n", 4);
}
