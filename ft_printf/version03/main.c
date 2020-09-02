#include "libftprintf.h"

int main()
{
/*	printf("1|%5.d|\n", 0);
	printf("1|%05.d|\n", 0);
	printf("1|%-5.d|\n\n", 0);

	ft_printf("1|%5.d|\n", 0);
	ft_printf("1|%05.d|\n", 0);
	ft_printf("1|%-5.d|\n", 0);*/

	printf("1|%05d|\n", 25);
	printf("2|%5d|\n", 25);
	printf("3|%.5d|\n", 25);
	printf("4|%5.10d|\n", 25);
	printf("5|%10.5d|\n", 25);
	printf("6|%-10d|\n", 25);	
	printf("7|%-10.5d|\n", 25);
	printf("8|%.d|\n\n", 25);

	ft_printf("1|%05d|\n", 25);
	ft_printf("2|%5d|\n", 25);
	ft_printf("3|%.5d|\n", 25);
	ft_printf("4|%5.10d|\n", 25);
	ft_printf("5|%10.5d|\n", 25);
	ft_printf("6|%-10d|\n", 25);
	ft_printf("7|%-10.5d|\n", 25);
	ft_printf("8|%.d|\n", 25);

	return (0);
}
