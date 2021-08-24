/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:21:21 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 04:10:13 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_words(t_data *data)
{
	data->nb_words = ft_countwords(data->buffer, ' ');
	data->words = ft_split(data->buffer, ' ');
	return (0);	
}

int	ft_init_env(t_data *data, char **env)
{
	int i;

	i = 1;
	data->env = ft_create_first(env[0]);
	while (env[i])
	{
		ft_create_bot(&data->env, env[i]);
		i++;
	}
	return (i);
}

int	ft_init_exp(t_data *data, char **env)
{
	int	i;

	i = 1;
	data->exp = ft_create_first(env[0]);
	while (env[i])
	{
		ft_create_bot(&data->exp, env[i]);
		i++;
	}
	return (i);
}
