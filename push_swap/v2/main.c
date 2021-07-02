/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:09:57 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/02 16:49:48 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_pile	obj;

	if (ft_check_args(ac, &obj) < 0)
		return (-1);
	ft_init_pile(&obj.pileA, ac , av);
	ft_display(obj.pileA);
	
	ft_get_sort(ac, &obj);
	ft_display(obj.pileA);

//	ft_rrr(&obj);
//	ft_display(obj.pileB);
//	printf("%d\n", ft_check_pile(obj.pileB));

	return (0);
}
