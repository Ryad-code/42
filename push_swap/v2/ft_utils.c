#include "push_swap.h"

int ft_create_obj(t_nb **list, int nb, int index)
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

int	ft_create_obj2(t_nb **list, int nb , int index)
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

void	ft_delete_obj(t_nb **list)
{
	void	*tmp;

	tmp = (*list)->next;
	*list = NULL;
	free(*list);
	*list = tmp;
}

void	ft_rotate(t_nb **list)
{
	int	nb;
	int	index;

	nb = (*list)->nb;
	index = (*list)->index;
	ft_delete_obj(list);
	ft_create_obj2(list, nb, index);
}

void	ft_display(t_nb *list)
{
	printf("%4d |", list->nb);
	while (list->next)
	{
		list = list->next;
		printf("%4d |", list->nb);
	}
	printf("\n");
}
