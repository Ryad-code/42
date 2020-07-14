
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	conv
{
	int arg;
	int cursor;
	int width;
	int precision;
	int type;
}		sp_conv;

int	ft_printf(const char *s, ...);
void	ft_init(sp_conv);
void	ft_putchar(char c);
void	ft_putstr(const char *s, int n);
void	ft_putnbr(int nb);
int	fdcurs(const char *s);
void	ft_type(char c, sp_conv *conv);

#endif
