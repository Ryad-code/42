#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	obj;

	obj.nb_op = 0;
	obj.len_A = ac - 1;
	obj.len_B = 0;

	ft_create_root(&obj.pileA);
	ft_create_root(&obj.pileB);
	if (ft_valid_args(&obj, av) == -1)
	{
		printf("Wrong inputs");
		return (-1);
	}
	ft_init_pileA(&obj, av);

	ft_display(&obj);
	
/*	ft_pb(&obj);
	ft_pb(&obj);
	ft_ss(&obj);*/

//	ft_display(&obj);
	printf("len = %d\n", ft_check_pile(obj.pileA));
	printf("operations = %d\n", obj.nb_op);
	return (0);
}
