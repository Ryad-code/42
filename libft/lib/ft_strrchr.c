/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:22:03 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/12 18:33:39 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
