
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
	       j++;	
	}
	dest[i + j] = '\0';
	return (dest);
}

int ft_total_len(int size, char **strs, char *sep)
{
	int i;
	int len_strs;

	i = 1;
	len_strs = 0;
	while (i < size)
	{
		len_strs = len_strs + ft_strlen(strs[i]);
		i++;
	}
	return (len_strs + (ft_strlen(sep) * (size - 1)));
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int total_len;
	char *dest;

	i = 1;
	total_len = ft_total_len(size, strs, sep);
	dest = NULL;
	if (size == 0)
		return (dest);
	dest = malloc(sizeof(char) * (total_len + 1));
	dest[0] = '\0';
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);	
}

