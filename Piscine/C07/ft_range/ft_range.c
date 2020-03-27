
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int *ft_range(int min, int max)
{
	int i ;
	int diff;
	int *dest;

	i = 0;
	diff = max - min;
	dest = NULL;
	if (diff <= 0)
		return (dest);
	dest = malloc(sizeof(int) * diff);
	while (i < diff)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
