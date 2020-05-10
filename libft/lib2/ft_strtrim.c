/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:42:01 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/10 17:07:57 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str[i])
	{
		if (str[i] == c)
			dest = &str[i];
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char *s1, char *set)
{
	int i;
	int j;
	int k;
	char *dst;

	i = 0;
	j = 0;
	k = 0;
	dst = NULL;
	while (s1[i] && ft_strrchr(set, s1[i]))
		i++;
	k = i;
	while (s1[i] && !ft_strrchr(set, s1[i]))
	{
		i++;
		j++;
	}
	if (!(dst = malloc(sizeof(char) * j + 1)))
		return (dst);
	
	i = 0;
	while (i < j)
	{
		dst[i] = s1[i + k];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
