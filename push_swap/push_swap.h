#include <stdio.h>
#include <stdlib.h>

typedef struct		s_nb
{
	int		nb;
	int		index;
	int		f_index;
	struct s_nb	*prev;
}			t_nb;

int	ft_create_obj(t_nb **list, int nb, int index);

void	ft_swap(t_nb **list, int arg_nb);
void	ft_display_list(t_nb *list);

// Utils
int	ft_atoi(const char *str);
void	ft_swap_obj(t_nb *obj1, t_nb *obj2);
void    ft_r_rotate(t_nb **list, int arg_nb);
void	ft_rotate(t_nb **list, int arg_nb);
