
#include "ft_printf.h"

int	main()
{
	int nb = 25;
	int nb1 = 26;
	char *s = "bonjour";
	char c = 'X';

	printf("Nos int nb = %-04.2d, et nb1 = %-6.d\n", nb, nb1);

	ft_printf("Nos int nb = %-04.2d, et nb1 = %-6.d\n", nb, nb1);
	ft_printf("c = %c\n", c);
	ft_printf("s = %s\n", s);
	return (0);
}
