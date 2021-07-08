#include "push_swap.h"

void 	ft_swap(t_nb *obj1, t_nb *obj2)
{
	int	nb;
	
	nb = obj1->nb;
	obj1->nb = obj2->nb;
	obj2->nb = nb;
}

void    ft_rotate(t_nb **list)
{
	int	nb;

	nb = (*list)->nb;
	ft_delete(list);
	ft_create2(list, nb);
}

void    ft_r_rotate(t_nb **list)
{	
	int		nb;
	void	*tmp;

	tmp = *list;
	while ((*list)->next)
		*list = (*list)->next;
	nb = (*list)->nb;
	*list = tmp;
	ft_delete2(list);
	ft_create(list, nb);
}
