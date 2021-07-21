#include "push_swap.h"

void	ft_sa(t_data *obj)
{
	ft_swap(&obj->pileA);
	obj->nb_op++;
}

void	ft_sb(t_data *obj)
{
	ft_swap(&obj->pileB);
	obj->nb_op++;
}

void	ft_ss(t_data *obj)
{
	ft_swap(&obj->pileA);
	ft_swap(&obj->pileB);
	obj->nb_op++;
}

void	ft_pa(t_data *obj)
{
	ft_push(&obj->pileB, &obj->pileA);
	obj->nb_op++;
}

void    ft_pb(t_data *obj)
{
	ft_push(&obj->pileA, &obj->pileB);
	obj->nb_op++;
}

void	ft_ra(t_data *obj)
{
	ft_rotate(&obj->pileA);
	obj->nb_op++;
}

void	ft_rb(t_data *obj)
{
	ft_rotate(&obj->pileB);
	obj->nb_op++;
}

void	ft_rr(t_data *obj)
{
	ft_rotate(&obj->pileA);
	ft_rotate(&obj->pileB);
	obj->nb_op++;
}

void	ft_rra(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	obj->nb_op++;
}

void	ft_rrb(t_data *obj)
{
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
}

void	ft_rrr(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
}
