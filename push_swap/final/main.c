/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:27:20 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/09 10:48:22 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_data	obj;

	obj.nb_op = 0;
	ft_create_root(&obj.pileA);
	ft_create_root(&obj.pileB);
	ft_init_pileA(&obj, ac, av);
	if (ft_valid_args(&obj, ac, av) < 0)
	{
		write(1, "Error\n", 6);
		ft_delete_piles(obj.pileA);
		ft_delete(obj.pileB);
		return (-1);
	}
	if (ft_is_ordered(obj.pileA) == 0)
		return (0);
	ft_get_order(&obj);
	ft_get_sort(&obj);
	free(obj.order);
	ft_delete_piles(obj.pileA);
	ft_delete(obj.pileB);
	return (0);
}
