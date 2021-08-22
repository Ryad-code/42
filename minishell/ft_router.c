/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 00:45:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/22 02:44:00 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_router(t_data data)
{
	if (ft_strcmp(ECHO, data.words[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp(CD, data.words[0]) == 0)
		ft_cd(data);
	else if (ft_strcmp(PWD, data.words[0]) == 0)
		ft_pwd(data);
	else if (ft_strcmp(EXPORT, data.words[0]) == 0)
		ft_export(data);
	else if (ft_strcmp(UNSET, data.words[0]) == 0)
		ft_unset(data);
	else if (ft_strcmp(ENV, data.words[0]) == 0)
		ft_env(data);
	else if (ft_strcmp(EXIT, data.words[0]) == 0)
		ft_exit(data);
	else
		ft_exec(data);
	return (0);
}
