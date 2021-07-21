#include "push_swap.h"

void	ft_push(t_pile **from, t_pile **to)
{
	int	nb;

	nb = (*from)->next->nb;
	ft_delete((*from)->next);
	ft_create(to, nb);
}

void	ft_swap(t_pile **pile)
{
	int	nb;

	nb = (*pile)->next->next->nb;
	(*pile)->next->next->nb = (*pile)->next->nb;
	(*pile)->next->nb = nb;
}
