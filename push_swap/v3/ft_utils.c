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
	void	*tmp;
	t_pile *obj;

	tmp = *pile;
	obj = malloc(sizeof(t_pile));
	obj->nb = nb;
	obj->next = *pile;
	obj->prev = (*pile)->prev;
	(*pile)->prev = obj;
	*pile = obj->prev;
	(*pile)->next = obj;
	*pile = obj;
	return (0);
}

void	ft_init_pileA(t_data *obj ,char **av)
{
	int	i;

	i = 0;
	if (obj->len_A > 0)
		ft_first_create(&obj->pileA, ft_atoi(av[obj->len_A]));
	if (obj->len_A > 1)
		ft_second_create(&obj->pileA, ft_atoi(av[obj->len_A - 1]));
	if (obj->len_A > 2)
	{
		i = obj->len_A - 2;
		while (i > 0)
		{
			ft_create(&obj->pileA, ft_atoi(av[i]));
			i--;
		}
	}
}

void	ft_display_prev(t_pile *pile)
{
	void	*tmp;

	tmp = pile;
	while (pile->prev != tmp && pile->prev != NULL)
	{
		printf("%d\n", pile->nb);
		pile = pile->prev;
	}
	printf("%d\n", pile->nb);
}

void	ft_display_next(t_pile *pile)
{
	void	*tmp;
	
	tmp = pile;
	while (pile->next != tmp && pile->prev != NULL)
	{
		printf("%d\n", pile->nb);
		pile = pile->next;
	}
	printf("%d\n", pile->nb);
}
