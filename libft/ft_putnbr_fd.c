/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:10:32 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/09 14:20:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	put(int n, int fd)
{
	if (n / 10)
	{
		put(n / 10, fd);
		put(n % 10, fd);
	}
	else if (n > 0)
		ft_putchar_fd('0' + (char)n, fd);
	else
		ft_putchar_fd('0' + -(char)n, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	put(n, fd);
}
