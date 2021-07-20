#include <stdlib.h>
#include <stdio.h>

typedef struct	s_pile
{
	int		nb;
	void	*next;
	void	*prev;
}				t_pile;

typedef struct	s_data
{
	t_pile	*pileA;
	t_pile	*pileB;
	int		len_A;
	int		len_B;
	int		nb_op;
}				t_data;

int	ft_first_create(t_pile **pile, int nb);
int ft_second_create(t_pile **pile, int nb);
int	ft_create(t_pile **pile, int nb);

void	ft_init_pileA(t_data *obj, char **av);

void	ft_display_prev(t_pile *pile);
void    ft_display_next(t_pile *pile);

long		ft_atoi(char *str);
int			ft_isdigit(char c);
int     	ft_isint(char *str);
