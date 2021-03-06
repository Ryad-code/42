/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:00:53 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/09/16 15:46:13 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_p(t_parser *parser)
{
	parser->cursor = 0;
	parser->flag1 = 0;
	parser->flag2 = 0;
	parser->width = 0;
	parser->precision = 0;
	parser->is_p = 0;
}

void	ft_init_t(t_type *type)
{
	type->arg_len = 0;
	type->arg = 0;
	type->arg_int = 0;
	type->arg_u = 0;
	type->arg_char = '\0';
	type->arg_str = NULL;
	type->arg_pt = NULL;
	type->arg_hex = 0;
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		fdcurs(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			return (i);
		i++;
	}
	return (0);
}

int		ctcurs(const char *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i + 1])
	{
		if (s[i] == '%')
		{
			res++;
			if (s[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (res);
}
