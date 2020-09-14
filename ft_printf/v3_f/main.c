#include "libftprintf.h"

int main()
{
	char tab[16];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		tab[i] = i + 48;
		i++;
	}
	while (i < 16)
	{
		tab[i] = 'a' + j;
		i++;
		j++;
	}
	i = 0;
	while (i < 16)
	{
		printf("%c\n", tab[i]);
		i++;
	}	

	return (0);
}
