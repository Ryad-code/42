
#include "ft_printf.h"

int	main()
{
	int res;
	int nb = 123456789;
	int nb1 = 25250000;
//	char *s = "bonjour";
//	char c = 'X';
//	void	*pt = &s;

	res = printf("hex = %012x\n", nb1);
	printf("%d\n", res);

	res = ft_printf("hex = %012x\n", nb1);
	printf("%d\n", res);
	return (0);
}
