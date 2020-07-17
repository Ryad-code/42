
#include "ft_printf.h"

int	main()
{
	int nb = 25;
	int nb1 = 26;
	char *s = "bonjour";
	char c = 'X';

	printf("Nos int nb = %0*d, et nb1 = %02d\n", 4, nb, nb1);

	ft_printf("Nos int nb = %0*d, et nb1 = %03d\n", 4, nb, nb1);
//	ft_printf("c = %c\n", c);
//	ft_printf("s = %s\n", s);
	return (0);
}
