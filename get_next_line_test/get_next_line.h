/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:06:58 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/06/17 17:16:10 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);
int		fdcurs(char *s, int n);
int		ft_cat(char *dst, char *src , int n);
char	*setline(char *dst, char *src, int n);
char	*setrest(char *dst, char *src, int n);
char	*ft_loop(int fd, char *buff, char *dst);
char    *ft_swap(char *dst, char *src);


#endif
