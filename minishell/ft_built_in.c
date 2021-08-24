/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:55:12 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 05:50:19 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_data *data)
{
	int		i;

	i = 1;
	while (i < data->nb_words)
	{
		write(1, data->words[i], ft_strlen(data->words[i]));
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_cd(t_data *data)
{
	int res;

	res = chdir(data->words[1]);
	if (res < 0)
	{
		perror(data->words[1]);
		return (-1);
	}
	return (0);
}

int	ft_pwd(void)
{
	char *cwd = malloc(sizeof(char) * 1024);
	if (cwd == NULL)
		return (-1);
	getcwd(cwd, sizeof(char) * 1024);
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	free(cwd);
	return (0);
}

int	ft_export(t_data *data)
{
//	printf("nb = %d\n", data->nb_words);
	if (data->nb_words == 1)
		ft_display_list(data->exp);
	else
	{
		ft_create_in(&data->env, data->words[1] ,data->len_env - 1);
		ft_create_bot(&data->exp, data->words[1]);
	}
	return (0);
}

int	ft_unset(t_data data)
{
	
	return (0);
}

int	ft_env(t_data *data)
{
	ft_display_list(data->env);
	return (0);
}

int	ft_exec(t_data data)
{
	return (0);
}
