/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:22:03 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/12 20:49:53 by mlaouedj         ###   ########.fr       */
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
			dest = &s[i];
		i++;
	}
	return (dest);
}
