#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

char	*ft_reverse(char *str)
{
	int	i;
	int	j;
	int	len;
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
	int	i;
	int	nb;
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
	int	i;
	int	j;
	int	pid;
	char	*str;
	char	*tab;

	i = 0;
	pid = ft_atoi(av[1]);
//	printf("%d\n", pid);
	str = av[2];
//	printf("%s\n", str);

	while (str[i])
	{
		tab = ft_convert(str[i]);
		tab = ft_reverse(tab);
		j = 0;
		printf("%c |", str[i]);
		printf("%s|\n", tab);
		while (tab[j])
		{
			if (tab[j] == '1')
				kill(pid, SIGUSR1);
			else if (tab[j] == '0')
				kill(pid, SIGUSR2);
			usleep(250);
			j++;
		}
		ft_reset_tab(tab);
		i++;
	}
}
