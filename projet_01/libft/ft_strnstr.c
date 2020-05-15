/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 20:58:42 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/15 21:06:29 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	if (len < (size_t)ft_strlen(s2))
		return (NULL);
	while (s1[i] && i < (len - ft_strlen(s2)))
	{
		if (s1[i] == s2[0] && (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0))
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
