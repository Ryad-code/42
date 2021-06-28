#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int a)
{
	static int	nb;
	
	if (nb == 0)
		nb = 1;
	if (a == SIGUSR1)
	{
		printf("1");
	}
	else if (a == SIGUSR2)
		printf("0");
	if (nb % 8 == 0)
		printf("\n");
	nb++;
}

int main(int ac, char *av)
{
	printf("%d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
	}
}
