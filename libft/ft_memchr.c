/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:58:18 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/09 16:07:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*dst;

	i = 0;
	dst = (char *)s;
	while (i < n)
	{
		if (dst[i] == (char)c)
			return (&dst[i]);
		i++;
	}
	return (NULL);
}
