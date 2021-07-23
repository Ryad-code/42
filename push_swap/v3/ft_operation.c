#include "push_swap.h"

void	ft_sa(t_data *obj)
{
	ft_swap(&obj->pileA);
	obj->nb_op++;
	printf("sa\n");
}

void	ft_sb(t_data *obj)
{
	ft_swap(&obj->pileB);
	obj->nb_op++;
	printf("sb\n");
}

void	ft_ss(t_data *obj)
{
	ft_swap(&obj->pileA);
	ft_swap(&obj->pileB);
	obj->nb_op++;
	printf("ss\n");
}

void	ft_pa(t_data *obj)
{
	ft_push(&obj->pileB, &obj->pileA);
	obj->nb_op++;
	printf("pa\n");
}

void    ft_pb(t_data *obj)
{
	ft_push(&obj->pileA, &obj->pileB);
	obj->nb_op++;
	printf("pb\n");
}

void	ft_ra(t_data *obj)
{
	ft_rotate(&obj->pileA);
	obj->nb_op++;
	printf("ra\n");
}

void	ft_rb(t_data *obj)
{
	ft_rotate(&obj->pileB);
	obj->nb_op++;
	printf("rb\n");
}

void	ft_rr(t_data *obj)
{
	ft_rotate(&obj->pileA);
	ft_rotate(&obj->pileB);
	obj->nb_op++;
	printf("rr\n");
}

void	ft_rra(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	obj->nb_op++;
	printf("rra\n");
}

void	ft_rrb(t_data *obj)
{
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
	printf("rrb\n");
}

void	ft_rrr(t_data *obj)
{
	ft_r_rotate(&obj->pileA);
	ft_r_rotate(&obj->pileB);
	obj->nb_op++;
	printf("rrr\n");
}
