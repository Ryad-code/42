/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 00:45:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/22 01:12:23 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_router(t_data data)
{
	if (ft_strcmp(ECHO, data.cmd[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp(CD, data.cmd[0]) == 0)
		ft_cd(data);
	else if (ft_strcmp(PWD, data.cmd[0]) == 0)
		ft_pwd(data);
	else if (ft_strcmp(EXPORT, data.cmd[0]) == 0)
		ft_export(data);
	else if (ft_strcmp(UNSET, data.cmd[0]) == 0)
		ft_unset(data);
	else if (ft_strcmp(ENV, data.cmd[0]) == 0)
		ft_env(data);
	else if (ft_strcmp(EXIT, data.cmd[0]) == 0)
		ft_exit(data);
	return (0);
}
