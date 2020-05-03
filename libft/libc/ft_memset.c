/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:58:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/04/30 11:59:35 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
//	unsigned char *res;
	size_t i;

	i = 0;
	if (n == 0)
		return (str);
//	res = (unsigned char *)str;
	while (i < n)
	{
		((char*)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

int main()
{
	char *str = "Bonjour";
	void *p = &str;
	puts(str);
	printf("%p\n", memset(p, 20, 4));
	puts(str);
}
