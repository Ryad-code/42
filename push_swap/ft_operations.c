#include "push_swap.h"

void	ft_swap_obj(t_nb *obj1, t_nb *obj2)
{
	int	nb;
	int	index;
	int	f_index;

	nb = obj1->nb;
	f_index = obj1->f_index;

	obj1->nb = obj2->nb;
	obj1->f_index = obj2->f_index;

	obj2->nb = nb;
	obj2->f_index = f_index;
}

void	ft_swap(t_nb **list, int arg_nb)
{
	int	i;
	void	*tmp;

	i = 0;
	tmp = *list;
	while (i < (arg_nb - 2))
	{
		*list = (*list)->prev;
		i++;
	}
	ft_swap_obj(*list, (*list)->prev);
	*list = tmp;
}

void	ft_r_rotate(t_nb **list, int arg_nb)
{
	int	i;
	void	*tmp;

	i = 0;
	tmp = *list;
	while (i < arg_nb - 1)
	{
		ft_swap_obj(*list, (*list)->prev);
		*list = (*list)->prev;
		i++;
	}
	*list = tmp;
}

void	ft_rotate(t_nb **list, int arg_nb)
{
	int	i;

	i = 0;
	while (i < arg_nb - 1)
	{
		ft_r_rotate(list, arg_nb);
		i++;
	}
}
