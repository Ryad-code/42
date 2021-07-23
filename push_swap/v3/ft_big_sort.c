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

int	ft_get_med(t_pile *pile)
{
	int res;

	res = 0;
	if (ft_check_pile(pile) % 2 == 0)
		res = ft_even_med(pile);
	else if (ft_check_pile(pile) % 2 != 0)
		res = ft_odd_med(pile);
	return (res);
}

int		ft_get_nb_val(t_pile *pile)
{
	int	res;

	res = 0;
	if (ft_check_pile(pile) % 2 == 0)
		res  = ft_check_pile(pile) / 2;
	else
		res = (ft_check_pile(pile) / 2) + 1;
	return (res);
}



void	ft_sortA(t_data *obj)
{
	int	med;
	int	nb_val;

	med = ft_get_med(obj->pileA);
	nb_val = ft_get_nb_val(obj->pileA);
	printf("med = %d\n", med);
	while (nb_val > 0)
	{
		if (obj->pileA->next->nb > obj->pileA->next->next->nb)
			ft_sa(obj);
		if (obj->pileA->next->nb <= med)
		{
			ft_pb(obj);
			nb_val--;
		}
		else
			ft_ra(obj);
	}

}

void	ft_sortB(t_data *obj)
{
	int	med;
	int	nb_val;

	med = ft_get_med(obj->pileB);
	nb_val = ft_get_nb_val(obj->pileB);
	printf("med = %d\n", med);
	while (nb_val > 0)
	{
		if (obj->pileB->next->nb < obj->pileB->next->next->nb)
			ft_sb(obj);
		if (obj->pileB->next->nb >= med)
		{
			ft_pa(obj);
			nb_val--;
		}
		else 
			ft_rb(obj);
	}

}

void	ft_big_sort(t_data *obj, int it)
{

		ft_sortA(obj);
		ft_display(obj);
		while (ft_check_pile(obj->pileB) > 6)
		{	
			ft_sortB(obj);
			ft_display(obj);
		}
}
