#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int a)
{
	if (a == SIGUSR1)
	{
		printf("1\n");
	}
	else if (a == SIGUSR2)
		printf("0\n");
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
