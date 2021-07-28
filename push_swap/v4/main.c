#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	obj;
	t_pile	*tmp;

	obj.nb_op = 0;
	ft_create_root(&obj.pileA);
	ft_create_root(&obj.pileB);
	if (ft_valid_args(&obj, ac, av) == -1)
	{
		printf("Wrong inputs");
		return (-1);
	}
	ft_init_pileA(&obj, ac, av);
	ft_display(&obj);

	ft_get_order(&obj);
	ft_display_order(&obj, ac - 1);
//...........................................................
	ft_move_chunk1(&obj);
	
/*	ft_move(&obj);
	ft_pb(&obj);
	ft_move(&obj);
	ft_choose_spot(&obj, obj.pileA->next->nb);
	ft_pb(&obj);
	ft_move(&obj);
	ft_choose_spot(&obj, obj.pileA->next->nb);
	ft_pb(&obj);
	ft_move(&obj);
	ft_choose_spot(&obj, obj.pileA->next->nb);
	ft_pb(&obj);
	ft_move(&obj);
	ft_choose_spot(&obj, obj.pileA->next->nb);
	ft_pb(&obj);*/

	ft_display(&obj);

	printf("operations = %d, len_A = %d, len_B = %d\n", obj.nb_op, ft_check_pile(obj.pileA), ft_check_pile(obj.pileB));
	return (0);
}
