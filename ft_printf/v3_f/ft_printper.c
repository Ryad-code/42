/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:38:58 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:45:15 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printper(t_parser *parser, t_type *type)
{
	if (parser->flag1 == 0)
	{
		if (parser->flag2)
			ft_print0(parser->width - type->arg_len, type);
		else
			ft_printsp(parser->width - type->arg_len, type);
		ft_putchar('%');
	}
	else if (parser->flag1)
	{
		ft_putchar('%');
		ft_printsp(parser->width - type->arg_len, type);
	}
}
