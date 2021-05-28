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
	printf("A = |");
	ft_display(list_A);
	printf("B = |");
	ft_display(list_B);
	printf("\n");
}

void	ft_display(t_nb *list)
{
	printf("%4d |", list->nb);
	while (list->prev)
	{
		list = list->prev;
		printf("%4d |", list->nb);
	}
	printf("\n");
}

