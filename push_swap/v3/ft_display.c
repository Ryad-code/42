#include "push_swap.h"

void	ft_display_prev(t_pile *pile)
{
	void	*tmp;

	tmp = pile;
	if (pile->prev == tmp)
		printf("VIDE\n");
	while (pile->prev != tmp)
	{
		pile = pile->prev;
		printf("|%3d |\n", pile->nb);
	}
}

void	ft_display_next(t_pile *pile)
{
	void	*tmp;
	
	tmp = pile;
	if (pile->prev == tmp)
		printf("VIDE\n");
	while (pile->next != tmp)
	{
		pile = pile->next;
		printf("|%3d |\n", pile->nb);
	}
}

void	ft_display(t_data *obj)
{
	printf("Pile_A :\n");
	ft_display_next(obj->pileA);
	printf("\nPile_B :\n");
	ft_display_next(obj->pileB);
	printf("------------------------\n");
}
