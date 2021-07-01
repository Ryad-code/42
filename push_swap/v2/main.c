/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:09:57 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/07/01 11:26:55 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_nb *list;

	ft_create(&list, 40, 1);
	ft_display(list);

	ft_create(&list, 50, 1);
	ft_display(list);

	ft_create(&list, 60, 1);
	ft_display(list);

	ft_create2(&list, 30, 1);
	ft_display(list);

//	ft_delete2(&list);
	ft_r_rotate(&list);
	ft_display(list);

	return (0);
}
