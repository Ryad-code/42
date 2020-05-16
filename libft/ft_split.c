/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:31:18 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/16 14:43:57 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char *s, char c)
{
	int i;
	int nb_w;

	i = 0;
	nb_w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			nb_w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb_w);
}

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

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	*dst;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	dst = NULL;
	tab = NULL;
	if (!(tab = malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (tab);
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			j = i;
		}
		while (s[i] && s[i] != c)
			i++;
		if ((ft_countwords(s, c) - k) > 0)
		{
			dst = ft_strndup(&s[j], i - j);
			tab[k] = dst;
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
