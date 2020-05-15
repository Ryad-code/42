/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/15 13:30:56 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str_d;
	char		*str_s;

	i = 0;
	str_d = (char *)dest;
	str_s = (char *)src;
	if (str_d > str_s)
	{
		i = 1;
		while (i <= n)
		{
			str_d[n - i] = str_s[n - i];
			i++;
		}
	}
	else
		while (i <= n && str_d[i] && str_s[i])
		{
			str_d[i] = str_s[i];
			i++;
		}
	return (dest);
}
