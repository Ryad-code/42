#include "push_swap.h"

int	ft_create_obj(t_nb **list, int nb, int index)
{
	t_nb	*obj;

	obj = malloc(sizeof(t_nb));
	if (obj == NULL)
		return(1);
	obj->nb = nb;
	obj->index = index;
	obj->f_index = 0;
	obj->prev = *list;
	*list = obj;

	return (0);
}

int	ft_create_list(t_nb **list, int ac, char **av)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		ft_create_obj(list, ft_atoi(av[i]), i);
		i++;
	}
	return (0);
}
