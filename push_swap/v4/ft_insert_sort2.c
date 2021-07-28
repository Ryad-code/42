#include "push_swap.h"

int  ft_find_spot(t_pile *pile, int nb)
{
	int		i;
	void	*tmp;

	i = 0;
	tmp = pile;
	pile = pile->next;
	while (nb < pile->nb)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void	ft_choose_spot(t_data *obj, int  nb)
{
	int	spot;
	int	len;

	spot = ft_find_spot(obj->pileB, nb);
	len = ft_check_pile(obj->pileB);
	if (spot > len / 2)
	{
		printf("spot = %d\n", len - spot);
		while (len - spot > 0)
		{
			ft_rrb(obj);
			spot++;
		}
	}
	else
	{
		printf("spot2 = %d\n", spot);
		while (spot > 0)
		{
			ft_rb(obj);
			spot--;
		}
	}
}
