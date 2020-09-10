#include "libftprintf.h"

int main()
{
	int res;
	char c;

	c = 'c';

	res = 0;
	res = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	printf("%d\n", res);
	printf("\n");
	res = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	printf("%d\n", res);

/*	printf("3|%.5s|\n", s);
	printf("4|%5.10s|\n", s);
	printf("5|%10.5s|\n", s);
	printf("6|%-10s|\n", s);	
	printf("7|%-10.5s|\n", s);
	printf("8|%.s|\n\n", s);

	ft_printf("1|%010s|\n", s);
	ft_printf("2|%5s|\n", s);
	ft_printf("3|%.5s|\n", s);
	ft_printf("4|%5.10s|\n", s);
	ft_printf("5|%10.5s|\n", s);
	ft_printf("6|%-10s|\n", s);
	ft_printf("7|%-10.5s|\n", s);
	ft_printf("8|%.s|\n", s);*/

	return (0);
}
