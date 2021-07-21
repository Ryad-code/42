#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	obj;

	obj.len_A = ac - 1;
	obj.len_B = 0;
//	printf("valid = %d\n", ft_valid_args(&obj, av));

/*	if (ft_valid_args(&obj, av) == -1)
		return (-1);
	ft_init_pileA(&obj, av);*/

	ft_create_root(&obj.pileA);		//initialisation des piles
	ft_create_root(&obj.pileB);

	ft_create(&obj.pileA, 25);
	ft_create(&obj.pileA, 26);
	ft_create(&obj.pileA, 27);

	ft_display_next(obj.pileA);
	printf("\n");
	ft_display_next(obj.pileB);

	ft_push(&obj.pileA, &obj.pileB);
	ft_push(&obj.pileA, &obj.pileB);
	ft_swap(&obj.pileB);

	ft_display_next(obj.pileA);
	printf("\n");
	ft_display_next(obj.pileB);
}
