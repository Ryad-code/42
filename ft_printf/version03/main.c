#include "libftprintf.h"

int main()
{
	void *p;
	
	p = NULL;
	printf("1|%p|\n", p);
//	printf("1|%05.7x|\n", 0);
//	printf("1|%-5.2x|\n\n", 0);

	ft_printf("1|%p|\n", p);
//	ft_printf("1|%05.7x|\n", 0);
//	ft_printf("1|%-5.2x|\n", 0);*/

/*	printf("1|%05x|\n", 25);
	printf("2|%5x|\n", 25);
	printf("3|%.5x|\n", 25);
	printf("4|%5.10x|\n", 25);
	printf("5|%10.5x|\n", 25);
	printf("6|%-10x|\n", 25);	
	printf("7|%-10.5x|\n", 25);
	printf("8|%.x|\n\n", 25);

	ft_printf("1|%05x|\n", 25);
	ft_printf("2|%5x|\n", 25);
	ft_printf("3|%.5x|\n", 25);
	ft_printf("4|%5.10x|\n", 25);
	ft_printf("5|%10.5x|\n", 25);
	ft_printf("6|%-10x|\n", 25);
	ft_printf("7|%-10.5x|\n", 25);
	ft_printf("8|%.x|\n", 25);*/

	return (0);
}
