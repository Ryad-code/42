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
	ft_pb(obj);	
}

void	ft_move_prev(t_data *obj, int nb)
{
	while (nb > 0)
	{
		ft_rra(obj);;
		nb--;
	}
	ft_pb(obj);
}

void	ft_move(t_data *obj)
{
	int	lim;

	lim = obj->order[19];
	if (ft_find_next(obj->pileA, lim) > ft_find_prev(obj->pileA, lim))
			ft_move_prev(obj, ft_find_prev(obj->pileA, lim));
	else
		ft_move_next(obj, ft_find_next(obj->pileA, lim));
}

void	ft_move_chunk1(t_data *obj)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		ft_move(obj);
		i++;
	}
}
