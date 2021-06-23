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
