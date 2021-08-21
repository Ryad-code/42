/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 23:27:20 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/22 01:18:43 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_data data)
{
	int i;

	i = 1;
	while (i < data.nb_words)
	{
		printf("%s ", data.words[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	ft_cd(t_data data)
{
	return (0);
}

int	ft_pwd(t_data data)
{
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
