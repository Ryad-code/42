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
//.......................................................
int		ft_check_pile(t_nb *pile);
int		ft_check_pile_3(t_pile *obj);
int		ft_check_pile_4(t_pile *obj);
int		ft_check_args(int ac , t_pile *obj);
//.......................................................
void	ft_get_sort(int ac, t_pile *obj);
void	ft_sort_2(t_pile *obj);
void	ft_sort_3(t_pile *obj);
void	ft_sort_4(t_pile *obj);
