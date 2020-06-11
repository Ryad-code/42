/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:03:29 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/09 16:12:18 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (s[i])
	{
		if (s[i] == c)
			dest = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		dest = (char *)&s[i];
	return (dest);
}
