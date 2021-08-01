#include "pushswap.h"

int	main(int ac, char **av)
{
	t_data	obj;
	t_pile	*tmp;

	obj.nb_op = 0;
	ft_create_root(&obj.pileA);
	ft_create_root(&obj.pileB);
	if (ft_valid_args(&obj, ac, av) < 0)
	{
		write(1, "Wrong inputs\n", 13);
		return (ft_valid_args(&obj, ac, av));
	}
	ft_init_pileA(&obj, ac, av);
	ft_display(&obj);
	ft_get_order(&obj);
	ft_get_sort(&obj);	
	ft_display(&obj);

	printf("operations = %d, len_A = %d, len_B = %d\n", obj.nb_op, ft_check_pile(obj.pileA), ft_check_pile(obj.pileB));
	return (0);
}
