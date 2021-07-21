#include "push_swap.h"

int	ft_create_root(t_pile **pile)
{
	t_pile *obj;

	obj = malloc(sizeof(t_pile));
	if (obj == NULL)
		return (-1);
	obj->nb = 0;
	obj->prev = obj;
	obj->next = obj;
	*pile = obj;
	return (0);
}

int ft_create(t_pile **pile, int nb)
{
	t_pile *obj;

	obj = malloc(sizeof(t_pile));
	if (obj == NULL)
		return(-1);
	obj->nb = nb;
	obj->prev = *pile;
	obj->next = (*pile)->next;
	(*pile)->next = obj;
	obj->next->prev = obj;
	return (0);;;
}

int	ft_delete(t_pile *pile)
{
	pile->prev->next = pile->next;
	pile->next->prev = pile->prev;
	free(pile);
	return (0);
}
