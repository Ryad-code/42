#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	obj;

	obj.len_A = ac - 1;
	if (obj.len_A > 0)
		ft_init_pileA(&obj, av);

//	ft_display_prev(obj.pileA);
	ft_display_next(obj.pileA);


}
