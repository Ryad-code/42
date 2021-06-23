#include <stdio.h>
#include <stdlib.h>

typedef struct s_nb
{
	int		nb;
	int		index;
	void	*next;
}			t_nb;

int ft_create_obj(t_nb **list, int nb, int index);
void    ft_display(t_nb *list);
