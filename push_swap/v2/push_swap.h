#include <stdio.h>
#include <stdlib.h>

typedef struct s_nb
{
	int		nb;
	int		index;
	void	*next;
}			t_nb;

typedef struct	s_pile
{
	t_nb	*pileA;
	t_nb	*pileB;
}				t_pile;

int 	ft_create(t_nb **list, int nb, int index);
int		ft_create2(t_nb **list, int nb, int index);
void	ft_delete(t_nb **list);
void    ft_delete2(t_nb **list);

void	ft_init_list(t_nb **list, int ac , char **av);

void	ft_swap(t_nb *obj1, t_nb *ob2);
void	ft_rotate(t_nb **list);
void    ft_r_rotate(t_nb **list);

int	ft_atoi(const char *str);
void    ft_display(t_nb *list);
