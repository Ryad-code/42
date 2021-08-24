/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:21:21 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 01:54:37 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int 	ft_init_data(t_data *data)
{
	data->nb_words = ft_countwords(data->buffer, ' ');
	data->words = ft_split(data->buffer, ' ');
	return (0);	
}
