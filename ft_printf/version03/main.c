#include "libftprintf.h"

int main()
{
/*	printf("1|%5.d|\n", 0);
	printf("1|%05.7d|\n", 0);
	printf("1|%-5.2d|\n\n", 0);

	ft_printf("1|%5.d|\n", 0);
	ft_printf("1|%05.7d|\n", 0);
	ft_printf("1|%-5.2d|\n", 0);*/

	printf("1|%05u|\n", 25);
	printf("2|%5u|\n", 25);
	printf("3|%.5u|\n", 25);
	printf("4|%5.10u|\n", 25);
	printf("5|%10.5u|\n", 25);
	printf("6|%-10u|\n", 25);	
	printf("7|%-10.5u|\n", 25);
	printf("8|%.u|\n\n", 25);

	ft_printf("1|%05u|\n", 25);
	ft_printf("2|%5u|\n", 25);
	ft_printf("3|%.5u|\n", 25);
	ft_printf("4|%5.10u|\n", 25);
	ft_printf("5|%10.5u|\n", 25);
	ft_printf("6|%-10u|\n", 25);
	ft_printf("7|%-10.5u|\n", 25);
	ft_printf("8|%.u|\n", 25);

	return (0);
}
