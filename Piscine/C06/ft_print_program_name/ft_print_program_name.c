
#include <stdio.h>
#include <unistd.h>

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
	ft_putchar(av[0]);
}
