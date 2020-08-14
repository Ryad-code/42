#include "libftprintf.h"

int main()
{
//	ft_printf("|%6.d|\n", 0);
//	printf("|%6.d|\n", 0);
	int res;

	res = ft_printf("|%s|\n", "bonjour");
	printf("|%s|\n", "bonjour");
	printf("%d\n", res);
/*	printf("2|%10s|\n", "bonjour");
	printf("3|%12.10s|\n", "bonjour");
	printf("3|%-12.10s|\n", "bonjour");
	printf("4|%10.12s|\n", "bonjour");
	printf("3|%-10.12s|\n", "bonjour");
	printf("5|%.0s|\n", "bonjour");
	printf("|%010.6s|\n", "bonjour");*/

	return (0);
}
