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

void	ft_display_list(t_nb *list)
{
	int 	i;

	i = 0;
	while (list)
	{
		i++;
		printf(" %d |", list->nb);
		printf("i = %d\n", list->index);
//		printf("f_i = %d\n", list->f_index);
		list = list->prev;
	}
	printf("\n");
	printf("arg_nb  = %d\n", i);
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
