/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:33:11 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:43:17 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (!(dst = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (dst);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_print(const char *s, t_type *type)
{
	int i;

	i = 0;
	while (s[i] != '%' && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	type->f_len = type->f_len + i;
}

void	ft_print0(int nb, t_type *type)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		i++;
	}
	type->f_len = type->f_len + i;
}

void	ft_printsp(int nb, t_type *type)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
	type->f_len = type->f_len + i;
}
