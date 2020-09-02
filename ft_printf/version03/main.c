#include "libftprintf.h"

int main()
{
	int res;

	res = ft_printf("|%u|\n", 4294967284);
	printf("res = %d\n", res);

	res = printf("|%u|\n", 4294967284);
	printf("res = %d", res);


/*	ft_printf("3|%12.10s|\n", "bonjour");
	printf("3|%12.10s|\n\n", "bonjour");

	ft_printf("3|%-12.10s|\n", "bonjour");
	printf("3|%-12.10s|\n\n", "bonjour");

	ft_printf("4|%10.12s|\n", "bonjour");
	printf("4|%10.12s|\n\n", "bonjour");

	ft_printf("3|%-10.12s|\n", "bonjour");
	printf("3|%-10.12s|\n\n", "bonjour");

	ft_printf("5|%.0s|\n", "bonjour");
	printf("5|%.0s|\n\n", "bonjour");

//	ft_printf("|%010.6s|\n", "bonjour");
//	printf("|%010.6s|\n", "bonjour");*/

	return (0);
}
