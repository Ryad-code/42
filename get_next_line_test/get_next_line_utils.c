
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	fdcurs(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s[i] == '\n')
			return (i);
		if (s[i] == EOF)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_cat(char *dst, char *src, int len)
{
	int i;
	int j;
	int k;

	i = 0;
	j = ft_strlen(dst);
	k = 0;
	while (src[k] == '\n')
		k++;
	while (k < len)
	{
		dst[j + i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_swap(char *dst, char *src, int curs)
{
	char *tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(dst) + 1));
	tmp[0] = '\0';
	ft_cat(tmp, dst, ft_strlen(dst));
	printf("%s\n", tmp);
	free(dst);
	dst = malloc(sizeof(char) * (ft_strlen(tmp) + curs + 1));
	dst[0] = '\0';
	ft_cat(dst, tmp, ft_strlen(tmp));
//	printf("%s\n", dst);
	free(tmp);
	ft_cat(dst, src, curs);
	printf("%s\n", dst);
	return (dst);	
}
