/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:12:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/23 15:12:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		fdcurs(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		ft_cat(char *dst, char *src, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(dst);
	k = 0;
	while (src[k] == '\n')
		k++;
	while (i < len && src[k + i])
	{
		dst[i + j] = src[k + i];
		i++;
	}
	dst[i + j] = '\0';
	return (i);
}

char	*set_line(char *dst, char *src, int curs)
{
	char *tmp;

	tmp = NULL;
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(dst) + 1))))
		return (tmp);
	tmp[0] = '\0';
	ft_cat(tmp, dst, ft_strlen(dst));
	free(dst);
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(tmp) + curs + 1))))
		return (dst);
	dst[0] = '\0';
	ft_cat(dst, tmp, ft_strlen(tmp));
	free(tmp);
	ft_cat(dst, src, curs);
	return (dst);
}

char	*set_rest(char *rest)
{
	int		curs;
	char	*tmp;

	curs = fdcurs(rest);
	tmp = NULL;
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(rest) - curs + 1))))
		return (tmp);
	tmp[0] = '\0';
	ft_cat(tmp, &rest[curs], (ft_strlen(rest) - curs + 1));
	free(rest);
	rest = NULL;
	if (!(rest = malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (rest);
	rest[0] = '\0';
	ft_cat(rest, tmp, ft_strlen(tmp));
	free(tmp);
	return (rest);
}
