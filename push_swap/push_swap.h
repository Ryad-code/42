#include <stdio.h>
#include <stdlib.h>

typedef struct		s_nb
{
	int		nb;
	int		index;
	int		f_index;
	struct s_nb	*prev;
}			t_nb;

//Init
int	ft_create_obj(t_nb **list, int nb, int index);
int	ft_create_list(t_nb **list, int ac, char **av);

//Movements
void    ft_swap_obj(t_nb *obj1, t_nb *obj2);
void	ft_swap(t_nb **list, int arg_nb);
void    ft_rotate(t_nb **list, int arg_nb);
void    ft_r_rotate(t_nb **list, int arg_nb);

// Utils
int	ft_atoi(const char *str);
void    ft_display_list(t_nb *list_A, t_nb *list_B);
void    ft_display_list2(t_nb *list_A, t_nb *list_B);
