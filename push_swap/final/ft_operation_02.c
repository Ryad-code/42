/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:46:35 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/01 04:30:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pb(t_data *obj)
{
	ft_push(&obj->pileA, &obj->pileB);
	obj->nb_op++;
	write(1, "pb\n", 3);
}

void	ft_ra(t_data *obj)
{
	ft_rotate(&obj->pileA);
	obj->nb_op++;
	write(1, "ra\n", 3);
}

void	ft_rb(t_data *obj)
{
	ft_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rb\n", 3);
}

void	ft_rr(t_data *obj)
{
	ft_rotate(&obj->pileA);
	ft_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rr\n", 3);
}
