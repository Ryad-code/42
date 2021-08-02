/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:36:01 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/02 23:54:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pile
{
	int				nb;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

typedef struct s_data
{
	t_pile			*pileA;
	t_pile			*pileB;
	int				min;
	int				max;
	int				*order;
	int				nb_op;
}					t_data;

int					ft_create_root(t_pile **pile);
int					ft_create(t_pile **pile, int nb);
int					ft_delete(t_pile *pile);
void				ft_init_pileA(t_data *obj, int ac, char **av);
void				ft_init_printing(t_data *obj);
void				ft_display_prev(t_pile *pile);
void				ft_display_next(t_pile *pile);
void				ft_display_order(t_data *obj, int nb);
void				ft_display(t_data *obj);
void				ft_push(t_pile **from, t_pile **to);
void				ft_swap(t_pile **pile);
void				ft_rotate(t_pile **pile);
void				ft_r_rotate(t_pile **pile);
void				ft_sa(t_data *obj);
void				ft_sb(t_data *obj);
void				ft_ss(t_data *obj);
void				ft_pa(t_data *obj);
void				ft_pa(t_data *obj);
void				ft_pb(t_data *obj);
void				ft_ra(t_data *obj);
void				ft_rb(t_data *obj);
void				ft_rr(t_data *obj);
void				ft_rra(t_data *obj);
void				ft_rrb(t_data *obj);
void				ft_rrr(t_data *obj);
long				ft_atoi(char *str);
int					ft_isdigit(char c);
int					ft_isint(char *str);
int					ft_is_double(t_pile *pile, int nb);
int					ft_check_doubles(t_pile *pile);
int					ft_valid_args(t_data *obj, int ac, char **av);
int					ft_check_pile(t_pile *pile);
int					ft_get_min(t_pile *pile);
int					ft_is_in_pile(t_pile *pile, int val);
void				ft_get_order(t_data *obj);
int					ft_find_next(t_pile *pile, int nb);
int					ft_find_prev(t_pile *pile, int nb);
void				ft_move_next(t_data *obj, int nb);
void				ft_move_prev(t_data *obj, int nb);
int					ft_spot_in(t_pile *pile);
int					ft_spot_out(t_pile *pile, int nb);
void				ft_get_spotA(t_data *obj, int lim);
void				ft_get_spotB(t_data *obj, int nb);
void				ft_choose_path(t_data *obj, int spot);
int					ft_find_min(t_pile *pile);
void				ft_push_first_chunk(t_data *obj, int lim, int nb_val);
void				ft_push_chunk(t_data *obj, int lim, int nb_val);
void				ft_push_back(t_data *obj);
int					ft_get_chunk_len(int nb_arg);
int					ft_get_chunk_nb(int nb_arg);
int					ft_get_rest(int nb_arg);
void				ft_insert_sort(t_data *obj);
void				ft_get_sort(t_data *obj);
void				ft_sort_2(t_data *obj);
int					ft_check_sort3(t_pile *pile);
void				ft_sort_3(t_data *obj);
void				ft_sort_4(t_data *obj);
void				ft_sort_5(t_data *obj);
void				ft_sort_6(t_data *obj);
void				ft_default_sort(t_data *obj);
t_pile				*ft_get_minA(t_pile *pile);
int					ft_find_min(t_pile *pile);
void				ft_push_minA(t_data *obj);

#endif
