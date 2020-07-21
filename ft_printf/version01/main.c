
#include "ft_printf.h"

int	main()
{
	int nb = -25;
	int nb1 = 26;
	char *s = "bonjour";
	char c = 'X';
	void	*pt = &s;

	printf("pt = %p\n", pt);

	ft_printf("pt = %p\n", pt);

	return (0);
}
