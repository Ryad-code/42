/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:13:51 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/06 16:30:46 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *s1, char *s2, int len)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	res = 0;
	while (s1[i])
	{
		while (s1[i + j] && s1[i + j] == s2[j] && j < len)
		{
			if (j == 0)
				res = i;
			j++;
		}
		if (j == len)
			return (&s1[res]);
		j = 0;
		i++;
	}
	return (NULL);
}
