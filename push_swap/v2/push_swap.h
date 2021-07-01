#include <stdio.h>
#include <stdlib.h>

typedef struct s_nb
{
	int		nb;
	int		index;
	void	*next;
}			t_nb;

int 	ft_create(t_nb **list, int nb, int index);
int		ft_create2(t_nb **list, int nb, int index);
void	ft_delete(t_nb **list);
void    ft_delete2(t_nb **list);
void	ft_rotate(t_nb **list);
void    ft_r_rotate(t_nb **list);

void    ft_display(t_nb *list);
