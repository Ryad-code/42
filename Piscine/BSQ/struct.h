#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	int size;
	char full;
	char empty;
	char obstacle;
	char **tab_map;
}					t_map;

int	ft_strlen(char *str);
int	ft_check_first_str(char **tab);
int	ft_get_nb_str(char **tab);
int	ft_check_len_str(char **tab);
#endif
