/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/06 16:18:47 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *str, int c, size_t n)
{
	size_t		i;
	char		*dst;

	i = 0;
	dst = (char *)str;
	while (i < n)
	{
		if (dst[i] == (unsigned char)c)
			return (&dst[i]);
		i++;
	}
	return (NULL);
}
