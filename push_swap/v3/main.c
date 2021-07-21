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

//	ft_display(&obj);
	printf("med = %d\n", ft_even_med(obj.pileA));
	printf("operations = %d, len_A = %d, len_B = %d\n", obj.nb_op, obj.len_A, obj.len_B);
	return (0);
}
