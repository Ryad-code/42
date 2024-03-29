#include <stdlib.h>
#include <stdio.h>

typedef struct	s_pile
{
	int		nb;
	struct s_pile	*next;
	struct s_pile	*prev;
}				t_pile;

typedef struct	s_data
{
	t_pile	*pileA;
	t_pile	*pileB;
	int		*order;
	int		nb_op;
}				t_data;

int 	ft_create_root(t_pile **pile);				//creating functions
int 	ft_create(t_pile **pile, int nb);
int		ft_delete(t_pile *pile);
void	ft_init_pileA(t_data *obj, int ac, char **av);

void	ft_display_prev(t_pile *pile);				//display
void    ft_display_next(t_pile *pile);
void	ft_display(t_data *obj);

void	ft_push(t_pile **from, t_pile **to);		//basic operations
void    ft_swap(t_pile **pile);
void	ft_rotate(t_pile **pile);
void	ft_r_rotate(t_pile **pile);

void	ft_sa(t_data *obj);							//final operations
void    ft_sb(t_data *obj);
void    ft_ss(t_data *obj);
void    ft_pa(t_data *obj);
void	ft_pa(t_data *obj);
void    ft_pb(t_data *obj);
void    ft_ra(t_data *obj);
void    ft_rb(t_data *obj);
void    ft_rr(t_data *obj);
void    ft_rra(t_data *obj);
void    ft_rrb(t_data *obj);
void    ft_rrr(t_data *obj);

long	ft_atoi(char *str);						//arguments checking
int		ft_isdigit(char c);
int     ft_isint(char *str);
int		ft_valid_args(t_data *obj, int ac, char **av);

int		ft_check_pile(t_pile *pile);			//pile checking
int		ft_is_sorted(t_pile *pile);

int		ft_odd_med(t_pile *pile);				//Quick sort
int     ft_even_med(t_pile *pile);
int		ft_get_med(t_pile *pile);
void	ft_sortA(t_data *obj);
void    ft_sortB(t_data *obj);
void	ft_quick_sort(t_data *obj);

t_pile	*ft_get_min(t_pile *pile);				//Get/Push min value
void	ft_push_minA(t_data *obj);
void    ft_push_minB(t_data *obj);
int		ft_find_min(t_pile *pile);


void	ft_default_sort(t_data *obj);
void	ft_get_sortA(t_data *obj);				//Basic sort
void    ft_get_sortB(t_data *obj);
void	ft_sortA_2(t_data *obj);
void    ft_sortB_2(t_data *obj);
void    ft_sortA_3(t_data *obj);
void    ft_sortB_3(t_data *obj);
void    ft_sortA_4(t_data *obj);
void    ft_sortB_4(t_data *obj);
void    ft_sortA_5(t_data *obj);
void    ft_sortB_5(t_data *obj);
void    ft_sortA_6(t_data *obj);
void    ft_sortB_6(t_data *obj);

int		ft_check_sort3(t_pile *pile);

