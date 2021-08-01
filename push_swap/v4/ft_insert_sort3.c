#include "push_swap.h"

int	ft_get_chunk_len(int nb_arg)
{
	int	chunk_len;

	chunk_len = 0;
	if (nb_arg < 400)
		chunk_len = 20;
	else if (nb_arg < 500)
		chunk_len = 40;
	else if (nb_arg >= 500)
		chunk_len = 45;
	return (chunk_len);
}

int ft_get_chunk_nb(int nb_arg)
{
	int	chunk_nb;

	chunk_nb = 0;
	if (nb_arg < 400)
		chunk_nb = nb_arg / 20;
	else if (nb_arg < 500)
		chunk_nb = nb_arg / 40;
	else if (nb_arg >= 500)
		chunk_nb = nb_arg / 45;
	return (chunk_nb);
}

int	ft_get_rest(int nb_arg)
{
	int	rest;

	rest = 0;
	if (nb_arg < 400)
		rest = nb_arg % 20;
	else if (nb_arg < 500)
		rest = nb_arg % 40;
	else if (nb_arg == 500)
		rest = nb_arg % 45;
	return (rest);
}
