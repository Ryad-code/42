/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 23:27:20 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/22 03:08:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_data data)
{
	int		i;
	char	c;

	i = 1;
	c = ' ';
	while (i < data.nb_words)
	{
		write(1, data.words[i], ft_strlen(data.words[i]));
		write(1, &c, 1);
		i++;
	}
//	printf("%s ", data.words[1]);
//	printf("%s ", data.words[2]);
	printf("\n");
	return (0);
}

int	ft_cd(t_data data)
{
	struct dirent *read;
	DIR *rep;

	write(1, "bonjour", 7);
	rep = opendir(data.words[1]);
	return (0);
}

int	ft_pwd(t_data data)
{
	printf("ta mere la putasse");
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

int	ft_env(t_data data)
{
	return (0);
}

int	ft_exit(t_data data)
{
	return (0);
}

int	ft_exec(t_data data)
{
	return (0);
}
