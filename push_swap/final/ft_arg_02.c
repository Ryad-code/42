/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 04:19:27 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/09 10:48:42 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_valid_args(t_data *obj, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac - 1 < 1)
		return (-1);
	while (i <= ac - 1)
	{
		if (ft_isint(av[i]) == -1)
			return (-2);
		i++;
	}
	if (ft_check_doubles(obj->pileA) == -1)
		return (-3);
	return (0);
}

int	ft_is_ordered(t_pile *pile)
{
	void	*tmp;

	tmp = pile;
	pile = pile->next;
	while (pile->next != tmp)
	{
		if (pile->nb > pile->next->nb)
			return (-1);
		pile = pile->next;
	}
	return (0);
}
