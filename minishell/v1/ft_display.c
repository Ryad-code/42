/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:45:26 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 05:45:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_display_words(char **words, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		printf("%s\n", words[i]);
		i++;
	}

}

void	ft_display_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

void	ft_display_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	printf("%s\n", tmp->str);
}
