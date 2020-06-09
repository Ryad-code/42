/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:58:35 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/08 14:17:19 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str_d;
	char		*str_s;

	i = 0;
	str_d = (char *)dest;
	str_s = (char *)src;
	if ((!dest) && (!src))
		return (dest);
	while (i < n)
	{
		str_d[i] = str_s[i];
		i++;
	}
	return (dest);
}
