#include "libftprintf.h"

int main()
{
//	ft_printf("|%6.d|\n", 25);
//	printf("|%6.d|\n", 25);

	ft_printf("1|%012.6s|\n", "bonjour");
	printf("1|%012.6s|\n\n", "bonjour");

	ft_printf("2|%10s|\n", "bonjour");
	printf("2|%10s|\n\n", "bonjour");

	ft_printf("3|%12.10s|\n", "bonjour");
	printf("3|%12.10s|\n\n", "bonjour");

	ft_printf("3|%-12.10s|\n", "bonjour");
	printf("3|%-12.10s|\n\n", "bonjour");

	ft_printf("4|%10.12s|\n", "bonjour");
	printf("4|%10.12s|\n\n", "bonjour");

	ft_printf("3|%-10.12s|\n", "bonjour");
	printf("3|%-10.12s|\n\n", "bonjour");

	ft_printf("5|%.0s|\n", "bonjour");
	printf("5|%.0s|\n\n", "bonjour");

	ft_printf("|%010.6s|\n", "bonjour");
	printf("|%010.6s|\n", "bonjour");

	return (0);
}
