#include <stdio.h>
#include <stdlib.h>

typedef struct s_nb
{
	int		nb;
	int		index;
	void	*next;
}			t_nb;

int 	ft_create_obj(t_nb **list, int nb, int index);
int		ft_create_obj2(t_nb **list, int nb, int index);
void	ft_delete_obj(t_nb **list);
void	ft_rotate(t_nb **list);

void    ft_display(t_nb *list);
