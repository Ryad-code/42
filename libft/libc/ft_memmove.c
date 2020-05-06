/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/04/30 11:59:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t i;
	char *str_d = (char *)dest;
	char *str_s = (char *)src;

	i = 0;
	if ( str_d > str_s)
	{
		i = 1;
		while (i <= n)
		{
			str_d[n - i] = str_s[n - i];
			i++;
		}
	}
	else
		while (i <= n && str_d[i] && str_s[i]) 
		{
			str_d[i] = str_s[i];
			i++;
		}
	return (dest);
}
