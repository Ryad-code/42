/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:31:18 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 18:41:15 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

int ft_strncmp(char *str1, char *str2, int n)
{
	int i;

	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

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

char			**ft_split(char *s, char c)
{
	int		i[3];
	char	**tab;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	tab = NULL;
	if ((!s) || (!(tab = malloc(sizeof(char *) * (ft_countwords(s, c) + 1)))))
		return (tab);
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		i[1] = i[0];
		while (s[i[0]] && s[i[0]] != c)
			i[0]++;
		if ((ft_countwords(s, c) - i[2]) > 0)
		{
			tab[i[2]] = ft_strndup(&s[i[1]], i[0] - i[1]);
			i[2]++;
		}
	}
	tab[i[2]] = NULL;
	return (tab);
}
