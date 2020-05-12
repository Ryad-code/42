/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 20:58:42 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/12 21:00:45 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t res;

	i = 0;
	j = 0;
	res = 0;
	while (s1[i])
	{
		while (s1[i + j] && s1[i + j] == s2[j] && j < len)
		{
			if (j == 0)
				res = i;
			j++;
		}
		if (j == len)
			return (&s1[res]);
		j = 0;
		i++;
	}
	return (NULL);
}
