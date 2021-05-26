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
	ft_display_list2(list);
	printf(" %d |\n\n", list->nb);
}
void	ft_display_list2(t_nb *list)
{
	if (list->prev)
	{
		list = list->prev;
		ft_display_list2(list);
		printf(" %d |\n", list->nb);
	}
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

void	ft_r_rotate(t_nb **list, int arg_nb)
{
	int	i;
	void	*tmp;

	i = 0;
	tmp = *list;
	while (i < arg_nb - 1)
	{
		ft_swap_obj(*list, (*list)->prev);
		*list = (*list)->prev;
		i++;
	}
	*list = tmp;
}

void	ft_rotate(t_nb **list, int arg_nb)
{
	int	i;

	i = 0;
	while (i < arg_nb - 1)
	{
		ft_r_rotate(list, arg_nb);
		i++;
	}
}
