#include "push_swap.h"

int	ft_find_next(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 0;
	while (pile->next != tmp)
	{
		pile = pile->next;
		if (pile->nb <= nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_find_prev(t_pile *pile, int nb)
{
	void	*tmp;
	int		i;

	tmp = pile;
	i = 1;
	while (pile->prev != tmp)
	{
		pile = pile->prev;
		if (pile->nb <= nb)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_next(t_data *obj, int nb)
{
	while (nb > 0)
	{
		ft_ra(obj);;
		nb--;
	}
}

void	ft_move_prev(t_data *obj, int nb)
{
	while (nb > 0)
	{
		ft_rra(obj);;
		nb--;
	}
}

void	ft_get_spotA(t_data *obj, int lim)
{
	if (ft_find_next(obj->pileA, lim) > ft_find_prev(obj->pileA, lim))
		ft_move_prev(obj, ft_find_prev(obj->pileA, lim));
	else
		ft_move_next(obj, ft_find_next(obj->pileA, lim));
}

void	ft_push_first_chunk(t_data *obj, int lim, int nb_val)
{
	int	i;
	int	max;
	int min;

	i = 0;
	ft_get_spotA(obj, lim);
	ft_pb(obj);
	ft_get_spotA(obj, lim);
	ft_pb(obj);
	if (obj->pileB->next->nb < obj->pileB->prev->nb)
		ft_sb(obj);
	obj->max = obj->pileB->next->nb;
	obj->min = obj->pileB->prev->nb;
	while (i < nb_val - 2)
	{
		ft_get_spotA(obj, lim);
		ft_get_spotB(obj, obj->pileA->next->nb);
		ft_pb(obj);
		i++;
	}
}

void	ft_push_chunk(t_data *obj, int lim, int nb_val)
{
	int	i;
	
	i = 0;
	while (i < nb_val)
	{
		ft_get_spotA(obj, lim);
		ft_get_spotB(obj, obj->pileA->next->nb);
		ft_pb(obj);
		i++;
	}
}

int		ft_find_min(t_pile *pile)
{
	void	*tmp;
	int		i;
	int		res;
	int		res1;

	tmp = pile;
	i = 1;
	res = pile->next->nb;
	res1 = 1;
	pile = pile->next;
	while (pile->next != tmp)
	{
		if (res > pile->next->nb)
		{
			res = pile->next->nb;
			res1 = i + 1;
		}
		pile = pile->next;
		i++;
	}
	return (res1);
}

void	ft_push_back(t_data *obj)
{
	int	i;
	int	spot;

	i = 0;
	spot = ft_find_min(obj->pileB);
	ft_choose_path(obj, spot);
	while (i < 100)
	{
		ft_pa(obj);
		i++;
	}
}

void	ft_insert_sort(t_data *obj, int nb_val)
{
	int	i;
	int	chunk;
	int	rest;

	i = 0;
	chunk = nb_val / 5;
	rest = nb_val % 5;
	ft_push_first_chunk(obj, obj->order[chunk - 1], chunk);
	while (i < 4)
	{
		ft_push_chunk(obj, obj->order[(chunk * (i + 2)) - 1], chunk);
		i++;
	}
	ft_push_back(obj);
}
