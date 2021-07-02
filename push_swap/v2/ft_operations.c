#include "push_swap.h"

void	ft_sa(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2)
		ft_swap(obj->pileA, obj->pileA->next);
}

void    ft_sb(t_pile *obj)
{
	if (ft_check_pile(obj->pileB) >= 2)
		ft_swap(obj->pileB, obj->pileB->next);
}

void	ft_ss(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2 && ft_check_pile(obj->pileB) >= 2)
	{
		ft_swap(obj->pileA, obj->pileA->next);
		ft_swap(obj->pileB, obj->pileB->next);
	}
}

void	ft_pa(t_pile *obj)
{
	int	nb;
	int	index;

	if (ft_check_pile(obj->pileB) >= 1)
	{
		nb = obj->pileB->nb;
		index = obj->pileB->index;
		ft_delete(&obj->pileB);
		ft_create(&obj->pileA, nb, index);
	}
}

void    ft_pb(t_pile *obj)
{
	int	nb;
	int	index;

	if (ft_check_pile(obj->pileA) >= 1)
	{
		nb = obj->pileA->nb;
		index = obj->pileA->index;
		ft_delete(&obj->pileA);
		ft_create(&obj->pileB, nb , index);
	}
}

void	ft_ra(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2)
		ft_rotate(&obj->pileA);
}

void    ft_rb(t_pile *obj)
{
	if (ft_check_pile(obj->pileB) >= 2)
		ft_rotate(&obj->pileB);
}

void	ft_rr(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2 && ft_check_pile(obj->pileB) >= 2)
	{
		ft_rotate(&obj->pileA);
		ft_rotate(&obj->pileB);
	}
}

void	ft_rra(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2)
		ft_r_rotate(&obj->pileA);
}

void	ft_rrb(t_pile *obj)
{
	if (ft_check_pile(obj->pileB) >= 2)
		ft_r_rotate(&obj->pileB);
}

void	ft_rrr(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2 && ft_check_pile(obj->pileB) >= 2)
	{
		ft_r_rotate(&obj->pileA);
		ft_r_rotate(&obj->pileB);
	}
}
