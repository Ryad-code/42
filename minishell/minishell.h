/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:09:26 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/22 01:07:58 by mlaouedj         ###   ########.fr       */
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
# include "gnl/get_next_line.h"
//.............................................//Buildins
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

typedef struct s_data
{
	char	*buffer;
	char	**words;
	char	**cmd;
	int		nb_words;
	int		nb_cmd;
	char	**link;
}				t_data;
//.................................................Init
int     ft_init_data(t_data *data);
//.................................................Parsing
int		ft_strcmp(char *str1, char *str2);
char	*ft_strndup(char *from, int n);
int		ft_count(char *str, char sep);
char 	**ft_split(char *str, char sep);
//..................................................Router
int		ft_router(t_data data);
//..................................................Builtins functions
int		ft_echo(t_data data);
int		ft_cd(t_data data);
int		ft_pwd(t_data data);
int		ft_export(t_data data);
int		ft_unset(t_data data);
int		ft_env(t_data data);
int		ft_exit(t_data data);
//..................................................Display
void	ft_display_words(char **words, int nb);
#endif
