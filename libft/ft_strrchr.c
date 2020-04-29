
char *ft_strrchr(char *str, char c)
{
	int i;
	char *dest;

	i = 0;
	dest = NULL;
	while (str[i])
	{
		if (str[i] == c)
			dest = &str[i];
		i++;
	}
	return (dest);
}
