#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nb	*list_A;
	t_nb	*list_B;

	list_A = NULL;
	list_B = NULL;

	ft_create_list(&list_A, ac, av);
	ft_create_obj(&list_B, 25, 1);
	ft_create_obj2(&list_B, 50, 1);
	ft_create_obj2(&list_B, 150, 1);
	ft_create_obj2(&list_B, 200, 1);
	ft_create_obj2(&list_B, 250, 1);

	ft_display_list(list_A, list_B);

	ft_rotate(&list_A);
	ft_display_list(list_A, list_B);

	ft_rotate(&list_A);
	ft_display_list(list_A, list_B);

	ft_r_rotate(&list_A);
        ft_display_list(list_A, list_B);
	ft_r_rotate(&list_A);
        ft_display_list(list_A, list_B);

	return (0);
}	
