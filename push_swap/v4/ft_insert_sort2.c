#include "push_swap.h"

int		ft_spot_min(t_pile *pile)
{
	void	*tmp;
	int		res;
	int		res1;
	int		i;

	tmp = pile;
	res = pile->next->nb;
	res1 = 1;
	i  = 1;
	pile = pile->next;
	while (pile->next != tmp)
	{
		if (res > pile->next->nb)
		{
			res = pile->next->nb;
			res1 = i + 1;
		}
//		printf("res = %d, i = %d\n", res, i);
		pile = pile->next;
		i++;
	}
	return (res1);
}

int	ft_get_spot(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 1;
	while (pile->next != tmp)
	{
		pile = pile->next;
		if (nb < pile->nb && nb > pile->next->nb)
			return (i);
		i++;
	}
	return (-1);
}


void	ft_out_spot(t_data *obj, int nb, int *min, int *max)
{
	int	spot;
	int	len;

	spot = ft_spot_min(obj->pileB);
	len = ft_check_pile(obj->pileB);
	if (nb > *max || nb < *min)
	{
		spot = ft_spot_min(obj->pileB);
		ft_choose_path(obj, spot);
	}
	else
	{
		spot = ft_get_spot(obj->pileB, obj->pileA->next->nb);
		ft_choose_path(obj, spot);
	}
	printf("spot = %d, val = %d\n", spot, obj->pileA->next->nb);
	if (nb > *max)
		*max = nb;
	else if (nb <  *min)
		*min = nb;
}

void	ft_choose_path(t_data *obj, int spot)
{
	int len;

	len = ft_check_pile(obj->pileB);
	if (spot > len / 2)
	{
		while (len - spot > 0)
		{
			ft_rrb(obj);
			spot++;
		}
	}
	else
	{
		while (spot > 0)
		{
			ft_rb(obj);
			spot--;
		}
	}
}
