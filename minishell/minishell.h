/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:09:26 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/21 19:37:20 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "gnl/get_next_line.h"

int		ft_strcmp(char *str1, char *str2);
char	*ft_strndup(char *from, int n);
int		ft_count(char *str, char sep);
char 	**ft_split(char *str, char sep);

#endif
