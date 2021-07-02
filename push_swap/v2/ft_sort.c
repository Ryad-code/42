#include "push_swap.h"

void    ft_get_sort(int ac, t_pile *obj)
{
	int	nb_args;

	nb_args = ac - 1;
	if (nb_args == 2)
		ft_sort_2(obj);
	else if (nb_args == 3)
		ft_sort_3(obj);
	else if (nb_args == 4)
		ft_sort_4(obj);
}

void	ft_sort_2(t_pile *obj)
{
	void	*tmp;
	int		nb;

	tmp = obj->pileA;
	nb =  obj->pileA->nb;
	obj->pileA = obj->pileA->next;
	if (nb > obj->pileA->nb)
	{
		obj->pileA = tmp;
		ft_sa(obj);
	}
	obj->pileA = tmp;
}

void	ft_sort_3(t_pile *obj)
{
	int	order;

	order = ft_check_pile_3(obj);
	if (order == 2)
	{
		ft_sa(obj);
		ft_ra(obj);
	}
	else if (order == 3)
	{
		ft_sa(obj);
	}
	else if (order == 4)
	{
		ft_rra(obj);
	}
	else if (order == 5)
	{
		ft_ra(obj);
	}
	else if (order == 6)
	{
		ft_ra(obj);
		ft_sa(obj);
	}
}

void	ft_sort_4(t_pile *obj)
{
	int i;
	int	arg_min;

	i = 1;
	arg_min = ft_check_pile_4(obj);
	if (arg_min < 4)
	{
		while (i < arg_min)
		{
			ft_ra(obj);
			i++;
		}
		ft_pb(obj);
	}
	else if (arg_min == 4)
	{
		ft_rra(obj);
		ft_pb(obj);
	}
	ft_sort_3(obj);
	ft_pa(obj);
}
