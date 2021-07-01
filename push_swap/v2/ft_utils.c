#include "push_swap.h"

int ft_create(t_nb **list, int nb, int index)
{
	t_nb    *obj;
	obj = malloc(sizeof(t_nb));
	if (obj == NULL)
		return (1);
	obj->nb = nb;
	obj->index = index;
	obj->next = *list;
	*list = obj;
	return (0);
}

int	ft_create2(t_nb **list, int nb , int index)
{
	void	*tmp;
	t_nb	*obj;

	tmp = *list;
	obj = malloc(sizeof(t_nb));
	if (obj == NULL)
		return (1);
	while ((*list)->next)
		*list = (*list)->next;
	obj->nb = nb;
	obj->index = index;
	obj->next = NULL;
	(*list)->next = obj;
	*list = tmp;
	return (0);
}

void	ft_delete(t_nb **list)
{
	void	*tmp;

	tmp = (*list)->next;
	*list = NULL;
	free(*list);
	*list = tmp;
}

void	ft_delete2(t_nb **list)
{
	void	*tmp;
	void	*tmp2;

	tmp = *list;
	while ((*list)->next)
	{
		tmp2 = *list;
		*list = (*list)->next;
	}
	*list = NULL;
	free(*list);
	*list = tmp2;
	(*list)->next =  NULL;
	*list = tmp;
}

void	ft_init_list(t_nb **list, int ac, char **av)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		ft_create(list, ft_atoi(av[i]), i);
		i++;
	}
}
