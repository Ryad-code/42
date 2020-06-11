/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:03:52 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/11 16:48:56 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*dst;

	i = 0;
	dst = NULL;
	if ((!s) || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (!(dst = malloc(sizeof(char) * len + 1)))
		return (dst);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
