/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:02:54 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:40:44 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_loop(char *tmp, t_parser *parser, t_type *type, va_list list)
{
	ft_print(tmp, type);
	parser->cursor = fdcurs(tmp) + 1;
	ft_flags(&tmp[parser->cursor], parser);
	ft_width(&tmp[parser->cursor], parser, list);
	ft_precision1(&tmp[parser->cursor], parser, list);
	ft_deftype01(tmp, parser, type, list);
	type->f_len += type->arg_len;
}

int		ft_printf(const char *s, ...)
{
	int			i;
	char		*tmp;
	t_type		type;
	t_parser	parser;
	va_list		list;

	i = 0;
	tmp = ft_strdup(s);
	type.f_len = 0;
	va_start(list, s);
	while (i < ctcurs(s))
	{
		ft_init_t(&type);
		ft_init_p(&parser);
		ft_loop(tmp, &parser, &type, list);
		tmp = &tmp[parser.cursor + 1];
		i++;
	}
	ft_print(tmp, &type);
	tmp = NULL;
	free(tmp);
	return (type.f_len);
}
