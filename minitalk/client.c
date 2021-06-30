/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:40:00 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/06/30 16:09:27 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	tmp = malloc(sizeof(char) * 9);
	while (i < (8 - len))
	{
		tmp[i] = '0';
		i++;
	}
	while (j < len)
	{
		tmp[i] = str[len - j - 1];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free (str);
	return (tmp);
}

char	*ft_convert(char a)
{
	int		i;
	int		nb;
	char	*tab;

	i = 0;
	nb = a;
	tab = malloc((sizeof(char) * 8) + 1);
	while (nb >= 1)
	{
		tab[i] = (nb % 2) + 48;
		nb = nb / 2;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	ft_reset_tab(char *tab)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		tab[i] = '\0';
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;
	char	*tab;

	i = 0;
	str = av[2];
	(void)ac;
	while (str[i])
	{
		tab = ft_convert(str[i]);
		tab = ft_reverse(tab);
		j = 0;
		while (tab[j])
		{
			if (tab[j] == '1')
				kill(ft_atoi(av[1]), SIGUSR1);
			else if (tab[j] == '0')
				kill(ft_atoi(av[1]), SIGUSR2);
			usleep(250);
			j++;
		}
		ft_reset_tab(tab);
		i++;
	}
}
