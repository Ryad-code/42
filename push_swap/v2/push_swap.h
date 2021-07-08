#include <stdio.h>
#include <stdlib.h>

typedef struct s_nb
{
	int		nb;
	void	*next;
}			t_nb;

typedef struct	s_pile
{
	t_nb	*pileA;
	t_nb	*pileB;
	int		*order;
	int		nb_arg;
	int		nb_op;
}				t_pile;

int 	ft_create(t_nb **list, int nb);
int		ft_create2(t_nb **list, int nb);
void	ft_delete(t_nb **list);
void    ft_delete2(t_nb **list);
void	ft_init_pile(t_nb **list, int ac , char **av);
//.......................................................
void	ft_swap(t_nb *obj1, t_nb *ob2);
void	ft_rotate(t_nb **list);
void    ft_r_rotate(t_nb **list);
//.......................................................
void	ft_sa(t_pile *obj);
void    ft_sb(t_pile *obj);
void    ft_pa(t_pile *obj);
void    ft_pb(t_pile *obj);
void	ft_ra(t_pile *obj);
void	ft_rb(t_pile *obj);
void	ft_rr(t_pile *obj);
void	ft_rra(t_pile *obj);
void    ft_rrb(t_pile *obj);
void    ft_rrr(t_pile *obj);
//.......................................................
int		ft_atoi(const char *str);
void    ft_display(t_nb *list);
void	ft_order_display(int nb, t_pile *obj);
//.......................................................
int		ft_check_pile(t_nb *pile);
int		ft_check_pile_3(t_pile *obj);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int		ft_check_min(t_pile *obj);
int		ft_check_order(t_nb *pile);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int		ft_check_nb(int nb, t_pile *obj);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int		ft_check_args(int ac , t_pile *obj);
//...............................................
void	ft_get_sort(t_pile *obj);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void	ft_push_min(int nb_args, t_pile *obj);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void	ft_sort_2(t_nb *pile, t_pile *obj);
void	ft_sort_3(t_pile *obj);
void	ft_sort_4(t_pile *obj);
void	ft_sort_5(t_pile *obj);
void	ft_sort_6(t_pile *obj);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void	ft_default_sort(t_pile *obj);
//.................................................BIG_SORT ALGO
int    ft_order_sort(t_nb *pile, t_pile *obj);
int		ft_get_med(int nb, int *tab);
void	ft_quick_sort(t_pile *obj);
//..................................................DELETE
void	ft_delete_tab(int nb, int *tab);
void    ft_delete_pile(int nb, t_nb **pile);
