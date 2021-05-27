#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

void	ft_display_list(t_nb *list_A, t_nb *list_B)
{
	ft_display_list2(list_A, list_B);
	printf(" | %d | ", list_A->nb);
	if (list_B)
		printf("| %d |\n\n", list_B->nb);
	else
		printf("\n\n");
}
void	ft_display_list2(t_nb *list_A, t_nb *list_B)
{
	void	*tmp;

	tmp = list_B;
	if (list_A->prev)
	{
		list_A = list_A->prev;
		if (list_B && list_B->prev)
			list_B = list_B->prev;
		ft_display_list2(list_A, list_B);
		printf(" | %d | ", list_A->nb);
		if (list_B != tmp)
			printf("| %d |\n", list_B->nb);
		else
			printf("\n");
	}
}
