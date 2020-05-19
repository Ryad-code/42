/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:16:38 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/19 14:05:36 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content)
	{
		new->content = malloc(sizeof(content));
		if (!new->content)
			return (NULL);
		ft_memcpy(new->content, content, sizeof(content));
	}
	else
	{
		new->content = NULL;
	}
	new->next = NULL;
	return (new);
}
