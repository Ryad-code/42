/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_len2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:28:13 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 13:28:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_arg_len4(s_type *type)
{
	int				i;
	unsigned long	nbu;

	i = 0;
	nbu = 0;
	if (type->arg == 4)
	{
		nbu = (unsigned long)type->arg_pt;
		while (nbu >= 16)
		{
			nbu = nbu / 16;
			i++;
		}
		type->arg_len = i + 1;
	}
}

void	ft_arg_len5(s_type *type)
{
	if (type->arg == 5)
		type->arg_len = 1;
}

void	ft_arg_len6(s_parser *parser, s_type *type)
{
	if (type->arg == 6)
	{
		if (parser->is_p && parser->precision < ft_strlen(type->arg_str))
			type->arg_len = parser->precision;
		else
			type->arg_len = ft_strlen(type->arg_str);
	}
}
