#include "push_swap.h"

int	main(int ac, char **av)
{
//	void(ac);
//	void(av);

	t_data	obj;

	ft_first_create(&obj.pileA, 1);
	ft_second_create(&obj.pileA, 2);
	ft_create(&obj.pileA, 3);
//	ft_create(&obj.pileA, 43);
	printf("%d\n", obj.pileA->nb);
	obj.pileA = obj.pileA->prev;
	printf("%d\n", obj.pileA->nb);
	obj.pileA = obj.pileA->prev;
	printf("%d\n", obj.pileA->nb);
//	obj.pileA = obj.pileA->prev;
//	printf("%d\n", obj.pileA->nb);
}
