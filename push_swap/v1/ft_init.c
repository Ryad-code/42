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

int     ft_create_obj2(t_nb **list, int nb, int index)
{
	void	*tmp;
	t_nb    *obj;
	
	tmp = *list;
	obj = malloc(sizeof(t_nb));
	if (obj == NULL)
		return(1);
	while ((*list)->prev)
		*list = (*list)->prev;
	obj->nb = nb;
	obj->index = index;
	obj->f_index = 0;
	obj->prev = NULL;
	(*list)->prev = obj;
	*list = tmp;
	return (0);
}

int	ft_delete_obj(t_nb **list)
{
	void	*tmp;
	void	*tmp2;

	tmp = *list;
	while ((*list)->prev)
	{
		tmp2 = *list;
		*list = (*list)->prev;
	}
	free(*list);
	*list = tmp2;
	(*list)->prev = NULL;
	*list = tmp;
	return (0);
}

int	ft_create_list(t_nb **list, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_create_obj(list, ft_atoi(av[i]), ac);
		i++;
	}
	return (0);
}
