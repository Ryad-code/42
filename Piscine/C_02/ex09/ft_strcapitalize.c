/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:50:33 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/02/15 23:41:33 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int j;

	j = 1;
	ft_strlowcase(str);
	if (str[0] > 96 && str[0] < 123)
		str[0] = str[0] - 32;
	while (str[j] != '\0')
	{
		if (((str[j - 1] < 'A' || str[j - 1] > 'Z') && (str[j - 1] < 'a'
		|| str[j - 1] > 'z') && (str[j - 1] < 48 || str[j - 1] > 57)))
		{
			if (str[j] > 96 && str[j] < 123)
				str[j] = str[j] - 32;
		}
		j++;
	}
	return (str);
}
