/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:58:56 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/08 14:22:48 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str_s;
	char		tmp[n];

	i = 0;
	str_s = (char *)src;
	if ((!dest) && (!src))
		return (dest);
	while (i < n)
	{
		tmp[i] = str_s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = tmp[i];
		i++;
	}
	return (dest);
}
