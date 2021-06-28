#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

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
	{
		res[i] = '1';
//		printf("1");
	}
	else if (a == SIGUSR2)
	{
		res[i] = '0';
//		printf("0");
	}
	i++;
	if (nb % 8 == 0)
	{
		printf("%s\n", res);
		i = 0;
	}
	nb++;
}

int main(int ac, char **av)
{
	printf("%d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
	}
}
