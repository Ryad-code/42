
#include "ft_printf.h"

int	main()
{
	int nb = -25;
	int nb1 = 26;
	char *s = "bonjour";
	char c = 'X';

	printf("the printf = %10.6s|\n", s);
	ft_printf("mon printf = %10.6s|\n\n", s);

//	printf("Nos int nb = %006d, et nb1 = %-07.6d|\n", nb, nb1);
//	ft_printf("Nos int nb = %006d, et nb1 = %-07.6d|\n", nb, nb1); 
//	ft_printf("c = %c\n", c);
//	ft_printf("s = %s\n", s);
	return (0);
}
