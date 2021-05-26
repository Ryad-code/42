#include "push_swap.h"

int	main(int ac, char** av)
{
	t_nb	*list_A;
	int	i;

	i = 1;
	list_A = NULL;
	while (i < ac)
	{
		ft_create_obj(&list_A, ft_atoi(av[i]), i);
		i++;
	}
	i = 0;
	ft_display_list(list_A);

//	ft_swap(&list_A, ac - 1);
	ft_rotate(&list_A, ac -1);
	ft_display_list(list_A);

	ft_r_rotate(&list_A, ac -1);
	ft_display_list(list_A);

	return (0);
}	
