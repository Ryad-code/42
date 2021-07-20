#include "push_swap.h"

int	ft_first_create(t_pile **pile, int nb)
{
	t_pile	*obj;
	obj = malloc(sizeof(t_pile));
	obj->nb = nb;
	obj->prev = NULL;
	obj->next = NULL;
	*pile = obj;
   return (0);	
}

int	ft_second_create(t_pile **pile, int nb)
{
	t_pile	*obj;
	obj = malloc(sizeof(t_pile));
	obj->nb = nb;
	obj->next = *pile;
	obj->prev = *pile;
	(*pile)->prev  = obj;
	(*pile)->next = obj;
  	*pile = obj;
	return (0);
}

int	ft_create(t_pile **pile, int nb)
{
	t_pile *obj;
	obj = malloc(sizeof(t_pile));
	obj->nb = nb;
	obj->next = *pile;
	obj->prev = (*pile)->prev;
	(*pile)->prev = obj;
	*pile = obj;
	return (0);
}
