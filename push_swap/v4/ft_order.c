#include "push_swap.h"

int		ft_get_min(t_pile *pile)
{
	void	*tmp;
	int		res;

	tmp = pile;
	res = pile->next->nb;
	pile = pile->next;
	while (pile->next != tmp)
	{
		if (res > pile->next->nb)
			res = pile->next->nb;
		pile = pile->next;
	}
	return (res);
}

int		ft_is_in_pile(t_pile *pile, int val)
{
	void	*tmp;

	tmp = pile;
	while (pile->next != tmp)
	{		
		pile = pile->next;
		if (val == pile->nb)
			return (0);
	}
	return (-1);
}

void	ft_get_order(t_data *obj)
{
	int	i;
	int	nb_val;
	int	min;

	i  = 0;
	nb_val = ft_check_pile(obj->pileA);
	min = ft_get_min(obj->pileA);
	obj->order = malloc(sizeof(int) * nb_val);
	while (min < 2147483647 && i < nb_val)
	{
		if (ft_is_in_pile(obj->pileA, min) == 0)
		{
			obj->order[i] = min;
			i++;
		}
		min++;
	}
}
