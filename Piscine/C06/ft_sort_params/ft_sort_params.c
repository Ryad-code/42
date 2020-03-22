#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void ft_putchar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	int i;
	char *tmp;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i  = 0;
		}
		i++;

	}
	
	i = 1;
	while (i < ac)
	{
		ft_putchar(av[i]);
		i++;
	}
	return (0);
}
