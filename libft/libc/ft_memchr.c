/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/04/30 11:59:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *str, int c, size_t n)
{
	size_t i;
	char *dest = (char *)str;

	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
		       return(&dest[i]);	
		i++;
	}
	return (NULL);
}
