/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/06 16:15:53 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t		i;
	char		*str_d;
	char		*str_s;

	i = 0;
	str_d = (char *)dst;
	str_s = (char *)src;
	while (i < n)
	{
		str_d[i] = str_s[i];
		if (str_s[i] == (char)c)
			return (&str_d[i + 1]);
		i++;
	}
	return (NULL);
}
