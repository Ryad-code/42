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
	int		len_A;
	int		len_B;
	int		nb_op;
}				t_data;

int ft_create_root(t_pile **pile);				//creating functions
int ft_create(t_pile **pile, int nb);
int	ft_delete(t_pile *pile);

void	ft_display_prev(t_pile *pile);			//display
void    ft_display_next(t_pile *pile);

void	ft_push(t_pile **from, t_pile **to);	//basic operations
void    ft_swap(t_pile **pile);					

void	ft_sa(t_pile **pile);					//final operations

long		ft_atoi(char *str);					//arguments checking
int			ft_isdigit(char c);
int     	ft_isint(char *str);
int			ft_valid_args(t_data *obj, char **av);
