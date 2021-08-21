/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:45:26 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/21 21:01:09 by mlaouedj         ###   ########.fr       */
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
