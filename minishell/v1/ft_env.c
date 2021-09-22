/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:45:05 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 20:00:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_sep(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_find_var(t_data *data, t_list *list)
{
	int i;
	int	n;
	t_list *tmp;

	i = 0;
	tmp = list;
	while (list->next)
	{
		n = ft_find_sep(list->str);
		if (ft_strncmp(list->str, data->words[1], n) == 0)
			return (i);
		i++;
		list = list->next;
	}
	list = tmp;
	return (-1);
}
