#include "push_swap.h"

void	ft_sa(t_data *obj)
{
	ft_swap(&obj->pileA);
	obj->nb_op++;
	write(1, "sa\n", 3);
}

void	ft_sb(t_data *obj)
{
	ft_swap(&obj->pileB);
	obj->nb_op++;
	write(1, "sb\n", 3);
}

void	ft_ss(t_data *obj)
{
	ft_swap(&obj->pileA);
	ft_swap(&obj->pileB);
	obj->nb_op++;
	write(1, "ss\n", 3);
}

void	ft_pa(t_data *obj)
{
	ft_push(&obj->pileB, &obj->pileA);
	obj->nb_op++;
	write(1, "pa\n", 3);
}

void    ft_pb(t_data *obj)
{
	ft_push(&obj->pileA, &obj->pileB);
	obj->nb_op++;
	write(1, "pb\n", 3);
}

void	ft_ra(t_data *obj)
{
	ft_rotate(&obj->pileA);
	obj->nb_op++;
	write(1, "ra\n", 3);
}

void	ft_rb(t_data *obj)
{
	ft_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rb\n", 3);
}

void	ft_rr(t_data *obj)
{
	ft_rotate(&obj->pileA);
	ft_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rr\n", 3);
}

void	ft_rra(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	obj->nb_op++;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_data *obj)
{
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
	write(1, "rrr\n", 4);
}
