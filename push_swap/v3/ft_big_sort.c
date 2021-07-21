#include "push_swap.h"

int	ft_odd_med(t_pile *pile)
{
	int		sup;
	int		inf;
	t_pile	*tmp;
	t_pile	*tmp1;

	tmp = pile;
	tmp1 = pile;
	while (pile->next != tmp)
	{
		sup = 0;
		inf = 0;
		pile = pile->next;
		while (tmp1->next != tmp)
		{
			tmp1 = tmp1->next;
			if (pile->nb > tmp1->nb)
				inf++;
			else if (pile->nb < tmp1->nb)
				sup++;
		}
		tmp1 = tmp1->next;
		if (sup == inf)
			return (pile->nb);
	}
	return (-1);
}

int	ft_even_med(t_pile *pile)
{
	int		sup;
	int		inf;
	t_pile	*tmp;
	t_pile	*tmp1;

	tmp = pile;
	tmp1 = pile;
	while (pile->next != tmp)
	{
		sup = 0;
		inf = 0;
		pile = pile->next;
		while (tmp1->next != tmp)
		{
			tmp1 = tmp1->next;
			if (pile->nb > tmp1->nb)
				inf++;
			else if (pile->nb < tmp1->nb)
				sup++;
		}
		tmp1 = tmp1->next;
		if (sup - inf < 2 && sup - inf > -2)
			return (pile->nb);
	}
	return (-1);
}
