#include "philosophers.h"

void	*ft_test1(void	*arg)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("hello\n");
		sleep(1);
		i++;
	}
	pthread_exit(NULL);
}

void	*ft_test2(void	*arg)
{
	int 	i;
	i = 0;
	while (i < 10)
	{
		printf("bye\n");
		sleep(1);
		i++;
	}
	pthread_exit(NULL);
}

int main(int ac, char **av)
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, ft_test1, NULL);
	pthread_create(&t2, NULL, ft_test2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
