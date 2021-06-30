/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:40:09 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/30 16:09:05 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert(char *str)
{
	int		i;
	int		res;
	int		pui;

	i = 0;
	res = 0;
	pui = 128;
	while (str[i])
	{
		res = res + (str[i] - 48) * pui;
		pui = pui / 2;
		i++;
	}
	write(1, &res, 1);
}

void	handler(int a)
{
	static int	i;
	static int	nb;
	static char	*res;

	if (!res)
		res = malloc(sizeof(char) * 9);
	if (!i)
		i = 0;
	if (nb == 0)
		nb = 1;
	if (a == SIGUSR1)
		res[i] = '1';
	else if (a == SIGUSR2)
		res[i] = '0';
	i++;
	if (nb % 8 == 0)
	{
		res[i] = '\0';
		ft_convert(res);
		i = 0;
	}
	nb++;
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	(void)ac;
	(void)av;
	ft_putnbr(pid);
//	printf("%d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
	}
	return (0);
}
