/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:42:01 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/16 16:46:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (dest);
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	int		k;
	char	*dst;

	i = 0;
	j = 0;
	k = 0;
	dst = NULL;
	while (s1[i] && ft_strrchr(set, s1[i]) != NULL)
		i++;
	k = i;
	while (s1[i] && ft_strrchr(set, s1[i]) == NULL)
	{
//		printf("%d\n", j);
		i++;
		j++;
	}
//	printf("%d\n", j);
//	printf("%d\n", i);
	dst = ft_strndup(&s1[k], j);
	return (dst);
}
