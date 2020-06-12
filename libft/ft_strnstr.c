/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:03:00 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/12 19:13:49 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (ft_strlen(s2) == 0 || len == 0)
		return ((char *)s1);
	while (i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j] && (i + j) < len)
			{
				if (j == ft_strlen(s2) - 1)
					return ((char *)&s1[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
