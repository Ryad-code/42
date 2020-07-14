
#include "ft_printf.h"

void	ft_type(char c, sp_conv *conv)
{
	if (c == 'c')
		conv->type = 1;
	if (c == 's')
		conv->type = 2;
	if (c == 'p')
		conv->type = 3;
	if (c == 'd' || c == 'i')
		conv->type = 4;
	if (c == 'x')
		conv->type = 5;
	if (c == 'X')
		conv->type = 6;
}
