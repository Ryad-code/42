
#include "ft_printf.h"

int	main()
{
	int nb = -25;
	int nb1 = 26;
	char *s = "bonjour";
	char c = 'X';

	printf("the printf = %0*.*d|\n", 5, 6, nb);
	ft_printf("mon printf = %0*.*d|\n\n", 5, 6, nb);

//	printf("Nos int nb = %006d, et nb1 = %-07.6d|\n", nb, nb1);
//	ft_printf("Nos int nb = %006d, et nb1 = %-07.6d|\n", nb, nb1); 
//	ft_printf("c = %c\n", c);
//	ft_printf("s = %s\n", s);
	return (0);
}
