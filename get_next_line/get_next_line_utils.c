/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:10:36 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/17 14:10:42 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_checkend_b(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int     ft_checkend_f(char *s, int size)
{
	int i;
	i = 0;
	while (i < size)
	{
		if (s[i] == EOF)
			return (i);
		i++;
	}
	return (i);
}
