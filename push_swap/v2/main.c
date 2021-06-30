#include "push_swap.h"

int main(int ac, char **av)
{
	t_nb *list;

	ft_create_obj(&list, 40, 1);
	ft_display(list);

	ft_create_obj(&list, 50, 1);
	ft_display(list);

	ft_create_obj(&list, 60, 1);
	ft_display(list);

	ft_create_obj2(&list, 30, 1);
	ft_display(list);

	ft_rotate(&list);
	ft_display(list);

	return (0);
}
