/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <mlaouedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:09:55 by mlaouedj          #+#    #+#             */
/*   Updated: 2020/05/12 18:26:32 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int	ft_atoi(char *str);
void 	*ft_bzero(void *s, size_t n);
int	ft_isalnum(char c);
int	ft_isalpha(char c);
int	ft_isascii(char c);
int	ft_isdigit(char c);
int	ft_isprint(char c);
void	*ft_memccpy(void *dst, void *src, int c, size_t n);
void	*ft_memchr(void *str, int c, size_t n);
int	ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strstr(char *str, char c);
char	*ft_strdup(char *str);
int	ft_strlcat(char *dst, char *src, unsigned int size);
int	ft_strlcpy(char *dst, char *src, size_t n);
int	ft_strlen(char *str);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(char *s1, char *s2, int len);
char	*ft_strrchr(char *str, char c);
char	ft_tolower(char c);
char	ft_toupper(char c);

// Partie II

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif
