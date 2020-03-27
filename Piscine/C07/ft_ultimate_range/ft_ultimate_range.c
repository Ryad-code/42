
#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int *range, int min, int max)
{
	int i;
	int diff;
	int *dest;

	i = 0;
	diff = max - min;
	dest = NULL;
	if (diff <= 0)
		return (0);
	dest = (int *) malloc(sizeof(int) * diff);
	while (i < diff)
	{
		dest[i] = min + i;
	       i++;	
	}
	*range =  dest;
	return (i - 1);
}
