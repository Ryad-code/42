/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:17:03 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/12 19:24:40 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_put(char *dst, char *s2, int i, int j)
{
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*dst;

	i = 0;
	j = 0;
	dst = NULL;
	if (!s1 || !s2)
		return (dst);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * len + 1)))
		return (dst);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	return (ft_put(dst, s2, i, j));
}
