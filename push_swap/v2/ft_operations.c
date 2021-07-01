#include "push_swap.h"

void	ft_sa(t_pile *obj)
{
	ft_swap(obj->pileA, obj->pileA->next);
}

void    ft_sb(t_pile *obj)
{
	ft_swap(obj->pileB, obj->pileB->next);
}

void	ft_ss(t_pile *obj)
{
	ft_swap(obj->pileA, obj->pileA->next);
	ft_swap(obj->pileB, obj->pileB->next);
}

void	ft_pa(t_pile *obj)
{
	int	nb;
	int	index;

	nb = obj->pileB->nb;
	index = obj->pileB->index;
	ft_delete(&obj->pileB);
	ft_create(&obj->pileA, nb, index);
}

void    ft_pb(t_pile *obj)
{
	int	nb;
	int	index;

	nb = obj->pileA->nb;
	index = obj->pileA->index;
	ft_delete(&obj->pileA);
	ft_create(&obj->pileB, nb , index);
}

void	ft_ra(t_pile *obj)
{
	ft_rotate(&obj->pileA);
}

void    ft_rb(t_pile *obj)
{
	ft_rotate(&obj->pileB);
}

void	ft_rr(t_pile *obj)
{
	ft_rotate(&obj->pileA);
	ft_rotate(&obj->pileB);
}
