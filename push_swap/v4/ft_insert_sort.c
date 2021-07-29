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

void	ft_move(t_data *obj)
{
	int	lim;

	lim = obj->order[19];
//	lim = obj->order[11];
	if (ft_find_next(obj->pileA, lim) > ft_find_prev(obj->pileA, lim))
		ft_move_prev(obj, ft_find_prev(obj->pileA, lim));
	else
		ft_move_next(obj, ft_find_next(obj->pileA, lim));
}

void	ft_move_chunk1(t_data *obj)
{
	int	i;
	int	max;
	int min;

	i = 0;
	ft_move(obj);
	ft_pb(obj);
	ft_move(obj);
	ft_pb(obj);
	if (obj->pileB->next->nb < obj->pileB->prev->nb)
		ft_sb(obj);
	max = obj->pileB->next->nb;
	min = obj->pileB->prev->nb;
	printf("min = %d, max = %d\n", min, max);
//.........................................................
	while (i < 18)
	{
		ft_move(obj);
		ft_out_spot(obj, obj->pileA->next->nb, &min, &max);
		printf("min = %d, max = %d\n", min, max);
		ft_pb(obj);
		i++;
	}
//	printf("min = %d, max = %d\n", min, max);
}
