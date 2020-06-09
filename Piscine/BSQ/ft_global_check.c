/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:31:24 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/02/26 23:24:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

int	ft_char_in_str(char **tab)
{
	int i;
	int j;
	int nb_str;
	int len_str;

	i = 1;
	nb_str = ft_get_nb_str(tab);
	len_str = ft_strlen(tab[0]);
	while (i < nb_str)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != tab[0][len_str - 2] &&
			tab[i][j] != tab[0][len_str - 3])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_global_check(char **tab)
{
	if (ft_str_is_printable(tab[0]) == 1)
		return (1);
	if (ft_check_first_str(tab) == 1)
		return (1);
	if (ft_check_len_str(tab) == 1)
		return (1);
	if (ft_char_in_str(tab) == 1)
		return (1);
	return (0);
}

int main()
{
		char *s1 = "1.ox";
		char *s2 = "";
//		char *s3 = "";
//		char *s4 = "";
//		char *s5 = "";
//		char *s6 = "";
		char *strs[6];

		strs[0] = s1;

		strs[1] = s2;
//		strs[2] = s3;
//		strs[3] = s4;
//		strs[4] = s5;
//		strs[5] = s6;

		printf("%d\n", ft_global_check(strs));
}
