/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:09:57 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/08 18:21:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_pile	obj;

	obj.nb_op = 0;
	obj.nb_arg = ac - 1;
	if (ft_check_args(ac, &obj) < 0)
		return (-1);
	ft_init_pile(&obj.pileA, ac , av);
	ft_display(obj.pileA);

	ft_quick_sort(&obj);
	
	printf("operations = %d\n", obj.nb_op);

	return (0);
}
