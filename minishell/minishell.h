/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:09:26 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 05:38:15 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include "gnl/get_next_line.h"
//.............................................//Build_in MACROS
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"
//................................................Listes chainees
typedef struct s_list
{
	char				*str;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;
//.................................................
typedef struct s_data
{
	char	*buffer;
	char	**words;
	int		nb_words;
	t_list	*env;
	int		len_env;
	t_list	*exp;
	int		len_exp;
	char	**link;
}				t_data;
//.................................................Init
int     ft_init_words(t_data *data);
int		ft_init_env(t_data *data, char **env);
int		ft_init_exp(t_data *data, char **env);
//.................................................Parsing
int		ft_strcmp(char *str1, char *str2);
int		ft_countwords(char *s, char c);
char	*ft_strndup(char *str, int n);
char	**ft_split(char *s, char c);
//..................................................Router
int		ft_router(t_data *data, char **env);
//..................................................Built_in functions
int		ft_echo(t_data *data);
int		ft_cd(t_data *data);
int		ft_pwd(void);
int		ft_export(t_data *data);
int		ft_unset(t_data data);
int		ft_env(t_data *data);
//..................................................Built_out functions
int		ft_exec(t_data data);
//..................................................Display
void	ft_display_words(char **words, int nb);
void	ft_display_env(char **env);
void	ft_display_list(t_list *list);
//..................................................Lists
t_list *ft_create_first(char *str);
int 	ft_create_top(t_list **list, char *str);
int 	ft_create_bot(t_list **list, char *str);
int 	ft_create_in(t_list **list, char *str, int curs);
int 	ft_delete_in(t_list **list, int curs);
//..................................................
#endif
