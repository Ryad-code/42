#include "libftprintf.h"

int main()
{
	int res;
	char c;

	c = 0;

	res = 0;
	printf("%5c\n", '\x00');
	printf("%d\n", res);
//	printf("\n");
	ft_printf("%5c\n", '\x00');
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
