
#include "ft_printf.h"

int	main()
{
	int nb = 25;
	char *s = "bonjour";
	char c = 'X';

	ft_printf("nb = %d\n", nb);
	ft_printf("c = %c\n", c);
	ft_printf("s = %s\n", s);
	return (0);
}
