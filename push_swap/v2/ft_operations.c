#include "push_swap.h"

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
