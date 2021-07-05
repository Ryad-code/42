#include "push_swap.h"

void	ft_sa(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2)
	{
		ft_swap(obj->pileA, obj->pileA->next);
		obj->nb_op++;
		printf("sa\n");
	}
		
}

void    ft_sb(t_pile *obj)
{
	if (ft_check_pile(obj->pileB) >= 2)
	{
		ft_swap(obj->pileB, obj->pileB->next);
		obj->nb_op++;
		printf("sb\n");
	}
}

void	ft_ss(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2 && ft_check_pile(obj->pileB) >= 2)
	{
		ft_swap(obj->pileA, obj->pileA->next);
		ft_swap(obj->pileB, obj->pileB->next);
		obj->nb_op++;
		printf("ss\n");
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
		obj->nb_op++;
		printf("pa\n");
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
		obj->nb_op++;
		printf("pb\n");
	}
}

void	ft_ra(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2)
	{
		ft_rotate(&obj->pileA);
		obj->nb_op++;
		printf("ra\n");
	}
}

void    ft_rb(t_pile *obj)
{
	if (ft_check_pile(obj->pileB) >= 2)
	{
		ft_rotate(&obj->pileB);
		obj->nb_op++;
		printf("rb\n");
	}
}

void	ft_rr(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2 && ft_check_pile(obj->pileB) >= 2)
	{
		ft_rotate(&obj->pileA);
		ft_rotate(&obj->pileB);
		obj->nb_op++;
		printf("rrr\n");
	}
}

void	ft_rra(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2)
	{
		ft_r_rotate(&obj->pileA);
		obj->nb_op++;
		printf("rra\n");
	}
}

void	ft_rrb(t_pile *obj)
{
	if (ft_check_pile(obj->pileB) >= 2)
	{
		ft_r_rotate(&obj->pileB);
		obj->nb_op++;
		printf("rrb\n");
	}
}

void	ft_rrr(t_pile *obj)
{
	if (ft_check_pile(obj->pileA) >= 2 && ft_check_pile(obj->pileB) >= 2)
	{
		ft_r_rotate(&obj->pileA);
		ft_r_rotate(&obj->pileB);
		obj->nb_op++;
		printf("rrr\n");
	}
}
