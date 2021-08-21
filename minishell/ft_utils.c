/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:09:04 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/21 19:48:11 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] & str2[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

char *ft_strndup(char *str, int n)
{
	int 	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		ft_count(char *str, char sep)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
		{
			while (str[i] != sep && str[i])
				i++;
			res++;
		}
	}
	return (res);
}

char	**ft_split(char *str, char sep)
{
	char **res;
	int 	i;
	int		j;
	int		len;

	res = malloc(sizeof(char *) * ft_count(str, sep));
	i = 0;
	j = 0;
	len = 0;
	while (str[j])
	{
		while (str[j] == sep)
			j++;
		while (str[j] != sep && str[j])
		{
			len++;
			j++;
		}
		res[i] = ft_strndup(&str[j - len], len);
		len = 0;
		i++;
		j++;
	}
	return (res);
}
