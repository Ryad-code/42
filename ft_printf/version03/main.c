#include "libftprintf.h"

int main()
{
	void* p;
	char* s = "bonjour";
//	s = NULL;
	
	printf("1|%*.*i|\n", -2, 1, 123456789);
	ft_printf("1|%*.*i|\n", -2, 1, 123456789);

/*	printf("1|%010s|\n", s);
	printf("2|%5s|\n", s);
	printf("3|%.5s|\n", s);
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
