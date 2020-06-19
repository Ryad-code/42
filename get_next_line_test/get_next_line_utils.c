
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
		i++;
	}
	return (i);
}

int	ft_cat(char *dst, char *src, int len)
{
	int j;
	int k;

	j = ft_strlen(dst);
	k = 0;
	while (src[k] == '\n')
		k++;
	while (k < len)
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	dst[j] = '\0';
	return (k);
}

char	*ft_swap(char *dst, char *src, int curs)
{
	char *tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(dst) + 1));
	tmp[0] = '\0';
	ft_cat(tmp, dst, ft_strlen(dst));
	free(dst);
	dst = malloc(sizeof(char) * (ft_strlen(tmp) + curs + 1));
	dst[0] = '\0';
	ft_cat(dst, tmp, ft_strlen(tmp));
	free(tmp);
	ft_cat(dst, src, curs);
	return (dst);	
}
