/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:55:12 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 02:05:53 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_data data)
{
	int		i;

	i = 1;
	while (i < data.nb_words)
	{
		write(1, data.words[i], ft_strlen(data.words[i]));
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_cd(t_data data)
{
	int res;

	res = chdir(data.words[1]);
	if (res < 0)
	{
		perror(data.words[1]);
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

int	ft_export(t_data data)
{

	return (0);
}

int	ft_unset(t_data data)
{
	return (0);
}

int	ft_env(t_data data, char **env)
{
	ft_display_env(env);
	return (0);
}

int	ft_exec(t_data data)
{
	return (0);
}
