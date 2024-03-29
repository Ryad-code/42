#include "push_swap.h"

void	ft_get_sortA(t_data *obj)
{
	int	nb_val;

	nb_val = ft_check_pile(obj->pileA);
	if (nb_val == 2)
		ft_sortA_2(obj);
	else if (nb_val == 3)
		ft_sortA_3(obj);
	else if (nb_val == 4)
		ft_sortA_4(obj);
	else if (nb_val == 5)
		ft_sortA_5(obj);
	else if (nb_val == 6)
		ft_sortA_6(obj);
}

void	ft_get_sortB(t_data *obj)
{
	int	nb_val;

	nb_val = ft_check_pile(obj->pileB);
	if (nb_val == 2)
		ft_sortB_2(obj);
	else if (nb_val == 3)
		ft_sortB_3(obj);
	else if (nb_val == 4)
		ft_sortB_4(obj);
	else if (nb_val == 5)
		ft_sortB_5(obj);
	else if (nb_val == 6)
		ft_sortB_6(obj);
}

void	ft_sortA_2(t_data *obj)
{
	if (obj->pileA->next->nb > obj->pileA->next->next->nb)
			ft_sa(obj);
}

void    ft_sortB_2(t_data *obj)
{
	if (obj->pileB->next->nb > obj->pileB->next->next->nb)
		ft_sb(obj);
}

int		ft_check_sort3(t_pile *pile)
{
	void	*tmp;
	int		i;
	int		tab[3];

	tmp = pile;
	i = 0;
	while (i < 3)
	{
		pile = pile->next;
		tab[i] = pile->nb;
		i++;
	}
	if (tab[0] < tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		return (1);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
		return (2);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		return (3);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		return (4);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		return (5);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		return (6);
	return (0);
}

void	ft_sortA_3(t_data *obj)
{
	int	order;

	order = ft_check_sort3(obj->pileA);
	if (order == 2)
	{
		ft_sa(obj);
		ft_ra(obj);
	}
	else if (order == 3)
		ft_sa(obj);
	else if (order == 4)
		ft_rra(obj);
	else if (order == 5)
		ft_ra(obj);
	else if (order == 6)
	{
		ft_ra(obj);
		ft_sa(obj);
	}
}

void	ft_sortB_3(t_data *obj)
{
	int	order;

	order = ft_check_sort3(obj->pileB);
	if (order == 2)
	{
		ft_sb(obj);
		ft_rb(obj);
	}
	else if (order == 3)
		ft_sb(obj);
	else if (order == 4)
		ft_rrb(obj);
	else if (order == 5)
		ft_rb(obj);
	else if (order == 6)
	{
		ft_rb(obj);
		ft_sb(obj);
	}
}

void	ft_sortA_4(t_data *obj)
{
	ft_push_minA(obj);
	ft_sortA_3(obj);
	ft_pa(obj);
}

void    ft_sortB_4(t_data *obj)
{
	ft_push_minB(obj);
	ft_sortB_3(obj);
	ft_pb(obj);
}

void    ft_sortA_5(t_data *obj)
{
	ft_push_minA(obj);
	ft_push_minA(obj);
	ft_sortA_3(obj);
	ft_pa(obj);
	ft_pa(obj);
}

void    ft_sortB_5(t_data *obj)
{
	ft_push_minB(obj);
	ft_push_minB(obj);
	ft_sortB_3(obj);
	ft_pb(obj);
	ft_pb(obj);
}

void    ft_sortA_6(t_data *obj)
{
	ft_push_minA(obj);
	ft_push_minA(obj);
	ft_push_minA(obj);
	ft_sortA_3(obj);
	ft_pa(obj);
	ft_pa(obj);
	ft_pa(obj);
}

void    ft_sortB_6(t_data *obj)
{
	ft_push_minB(obj);
	ft_push_minB(obj);
	ft_push_minB(obj);
	ft_sortB_3(obj);
	ft_pb(obj);
	ft_pb(obj);
	ft_pb(obj);
}

void	ft_default_sort(t_data *obj)
{
	int	nb_val;
	int	i;

	nb_val = ft_check_pile(obj->pileA);
	i = nb_val;
	while (nb_val > 0)
	{
		ft_push_minA(obj);
		nb_val--;
	}
	while (nb_val < i)
	{
		ft_pa(obj);
		nb_val++;
	}
}
