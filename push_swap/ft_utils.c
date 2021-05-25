#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

void	ft_swap_obj(t_nb *obj1, t_nb *obj2)
{
	int	nb;
	int	index;
	int	f_index;
	t_nb	*prev;

	nb = obj1->nb;
	index = obj1->index;
	f_index = obj1->f_index;
//	prev = obj1->prev;

	obj1->nb = obj2->nb;
	obj1->index = obj2->index;
	obj1->f_index = obj2->f_index;
//	obj1->prev = obj2->prev;

	obj2->nb = nb;
	obj2->index = index;
	obj2->f_index = f_index;
//	obj2->prev = prev;
}
