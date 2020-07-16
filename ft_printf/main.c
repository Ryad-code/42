
#include "ft_printf.h"

int	main()
{
	int nb = 25;
	int nb1 = 26;
	char *s = "bonjour";
	char c = 'X';

	ft_printf("Nos int nb = %-08d, et nb1 = %4d\n", nb, nb1);
//	ft_printf("c = %c\n", c);
//	ft_printf("s = %s\n", s);
	return (0);
}
