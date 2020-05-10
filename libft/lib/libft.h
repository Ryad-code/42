#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>

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

#endif
