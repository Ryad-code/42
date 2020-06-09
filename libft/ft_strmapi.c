/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:19:46 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/09 12:59:42 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;
	int				j;

	dst = NULL;
	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		if (!(dst = (char *)malloc(j * sizeof(char) + 1)))
			return (dst);
		while (s[i] != 0)
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (dst);
}
