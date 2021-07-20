#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	obj;

	obj.len_A = ac - 1;
	obj.len_B = 0;
//	printf("valid = %d\n", ft_valid_args(&obj, av));

	if (ft_valid_args(&obj, av) == -1)
		return (-1);
	ft_init_pileA(&obj, av);

//	ft_display_prev(obj.pileA);
	ft_display_next(obj.pileA);


}
