
#include "ft_printf.h"

int	main()
{
	int nb = 25;
	char *s = "bonjour";
	char c = 'X';

	ft_printf("Notre int nb = %---000012d, le char c = %c\n", nb, c);
//	ft_printf("c = %c\n", c);
//	ft_printf("s = %s\n", s);
	return (0);
}
