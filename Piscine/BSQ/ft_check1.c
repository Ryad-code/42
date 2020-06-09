/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:43:07 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/02/26 22:47:56 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_first_str(char **tab)
{
	int i;
	int len_str;

	i = 0;
	len_str = ft_strlen(tab[0]);
	if (len_str < 4)
		return (0);
	if (tab[0][len_str - 1] == tab[0][len_str - 2] ||
	tab[0][len_str - 1] == tab[0][len_str - 3] ||
	tab[0][len_str - 2] == tab[0][len_str - 3])
		return (1);
	return (0);
}

int	ft_get_nb_str(char **tab)
{
	int i;
	int len_str;
	int result;

	i = 0;
	len_str = ft_strlen(tab[0]);
	result = 0;
	while (tab[0][i] != tab[0][len_str - 3] && (tab[0][i] >= '0' &&
	tab[0][i] <= '9'))
	{
		result = result * 10 + (tab[0][i] - 48);
		i++;
	}
	return (result + 1);
}

int	ft_check_len_str(char **tab)
{
	int i;
	int nb_str;
	int basic_len;
	int total_len;

	i = 1;
	if ((nb_str = ft_get_nb_str(tab)) < 2)
		return (1);
	if ((basic_len = ft_strlen(tab[1])) < 1)
		return (1);
	total_len = 0;
	while (i < nb_str)
	{
		total_len = total_len + ft_strlen(tab[i]);
		i++;
	}
	if ((total_len / (nb_str - 1) != basic_len) ||
	(total_len % (nb_str - 1) != 0))
		return (1);
	return (0);
}
