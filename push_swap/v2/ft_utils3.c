#include "push_swap.h"

void 	ft_swap(t_nb *obj1, t_nb *obj2)
{
	int	nb;
	int index;
	
	nb = obj1->nb;
	index = obj1->index;
	obj1->nb = obj2->nb;
	obj1->index = obj2->index;
	obj2->nb = nb;
	obj2->index = index;
}

void    ft_rotate(t_nb **list)
{
	int	nb;
	int	index;

	nb = (*list)->nb;
	index = (*list)->index;
	ft_delete(list);
	ft_create2(list, nb, index);
}

void    ft_r_rotate(t_nb **list)
{	
	int		nb;
	int		index;
	void	*tmp;

	tmp = *list;
	while ((*list)->next)
		*list = (*list)->next;
	nb = (*list)->nb;
	index = (*list)->index;
	*list = tmp;
	ft_delete2(list);
	ft_create(list, nb, index);
}
