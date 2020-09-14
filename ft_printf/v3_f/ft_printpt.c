/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:29:06 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/14 16:49:59 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printpt(s_parser *parser, s_type *type)
{
	int res;

	res = 0;
	if (type->arg_pt == NULL)
		type->arg_len = 3;
	type->arg_hex = (unsigned long)type->arg_pt;
	if (parser->is_p && parser->precision == 0)
	{
		type->arg_len = 2;
		res = 1;
	}
	if (parser->flag1 == 0)
	{
		ft_printsp(parser->width - type->arg_len, type);
		ft_putstr("0x", 2);
		if (!res)
			ft_puthex(type->arg_hex);
	}
	if (parser->flag1)
	{
		ft_putstr("0x", 2);
		if (!res)
			ft_puthex(type->arg_hex);
		ft_printsp(parser->width - type->arg_len, type);
	}
}
