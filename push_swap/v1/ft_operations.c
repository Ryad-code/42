#include "push_swap.h"

void	ft_swap_obj(t_nb *obj1, t_nb *obj2)
{
	int	nb;
	int	f_index;

	nb = obj1->nb;
//	f_index = obj1->f_index;

	obj1->nb = obj2->nb;
//	obj1->f_index = obj2->f_index;

	obj2->nb = nb;
//	obj2->f_index = f_index;
}

void	ft_swap(t_nb **list)
{
	int	i;
	void	*tmp;
	void	*tmp2;

	i = 0;
	tmp = *list;
	while ((*list)->prev)
	{
		tmp2 = *list;
		*list = (*list)->prev;
		i++;
	}
	ft_swap_obj(*list, tmp2);
	*list = tmp;
}

void	ft_rotate(t_nb **list)
{
	void	*tmp;

	tmp = *list;
	if ((*list)->prev)
	{
		*list = (*list)->prev;
		ft_rotate(list);
	}
	ft_swap_obj(*list, tmp);
	*list = tmp;
}

void	ft_r_rotate(t_nb **list)
{
	void	*tmp;

	tmp = *list;
	while ((*list)->prev)
	{
		ft_swap_obj(*list, (*list)->prev);
		*list = (*list)->prev;
	}
	*list = tmp;
}

void	ft_push(t_nb **list_A, t_nb **list_B)
{
	void	*tmp;

	tmp = *list_A;
	while ((*list_A)->prev)
		*list_A = (*list_A)->prev;
	if (*list_B == NULL)
		ft_create_obj(list_B, (*list_A)->nb, 1);
	
	else
		ft_create_obj2(list_B, (*list_A)->nb, 1);
	*list_A = tmp;
	ft_delete_obj(list_A);
}
