
#include "libftprintf.h"

int	main()
{
	int res;
	int nb = 123456789;
	int nb1 = 25250000;
//	char *s = "bonjour";
//	char c = 'X';
//	void	*pt = &s;

	res = printf("hex = %012x et int = %-0016.11d|\n", nb1, nb);
	printf("%d\n", res);

	res = ft_printf("hex = %012x et int = %-0016.11d|\n", nb1, nb);
	printf("%d\n", res);
	return (0);
}
