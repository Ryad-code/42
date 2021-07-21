#include "push_swap.h"

void	ft_display_prev(t_pile *pile)
{
	void	*tmp;

	tmp = pile;
	while (pile->prev != tmp)
	{
		pile = pile->prev;
		printf("%d\n", pile->nb);
	}
}

void	ft_display_next(t_pile *pile)
{
	void	*tmp;
	
	tmp = pile;
	while (pile->next != tmp)
	{
		pile = pile->next;
		printf("%d\n", pile->nb);
	}
}
