#include "pushswap.h"

int	main(int ac, char **av)
{
	t_data	obj;

	obj.nb_op = 0;
	ft_create_root(&obj.pileA);
	ft_create_root(&obj.pileB);
	if (ft_valid_args(&obj, ac, av) < 0)
	{
		write(1, "Wrong inputs\n", 13);
		return (ft_valid_args(&obj, ac, av));
	}
	ft_init_pileA(&obj, ac, av);
	ft_get_order(&obj);
	ft_get_sort(&obj);	
	free(obj.order);
	ft_delete_piles(obj.pileA);
	ft_delete(obj.pileB);
	return (0);
}
