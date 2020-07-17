
#include "ft_printf.h"

void    ft_print(const char *s)
{
                int i;

                i = 0;
                while (s[i] != '%' && s[i] != '\0')
                {
                        ft_putchar(s[i]);
                        i++;
                }
}

void    ft_put_options(s_parser parser)
{
	int i;

	i = 0;
	if (parser.precision == 0)
        {
		while (i < parser.width)
		{

			if (parser.flag2 != 0 && parser.flag1 == 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}

}

void	ft_f_print(s_parser parser, s_type type)
{
	if (type.arg_int)
		ft_putnbr(type.arg_int);
	if (type.arg_char)
		ft_putchar(type.arg_char);
	if (type.arg_pchar)
		ft_putstr(type.arg_pchar);
}
