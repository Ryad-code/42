/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/04/30 11:59:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t i;
	char *str_d = (char *)dest;
	char *str_s = (char *)src;

	i = 0;
	while (i < n && str_d[i] && str_s[i])
	{
		str_d[i] = str_s[i];
		i++;
	}
	return (dest);
}
