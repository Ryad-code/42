#include "push_swap.h"

int	ft_check_pile(t_pile *pile)
{
	int i;
	t_pile *tmp;

	i = 0;
	tmp = pile;
	while (pile->next != tmp)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}
