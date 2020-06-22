
#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		fdcurs(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		ft_cat(char *dst, char *src, int len)
{
	int 	i;
	int 	j;
	int 	k;

	i = 0;
	j = ft_strlen(dst);
	k = 0;
	while (src[k] == '\n')
		k++;
	while (i < len && src[k + i])
	{
		dst[i + j] = src[k + i];
		i++;
	}
	dst[i + j] = '\0';
	return (i);
}
