/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:39:38 by labintei          #+#    #+#             */
/*   Updated: 2021/09/17 17:39:41 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strndup(char *str, int n)
{
	char *res;
	int i;

	i = 0;
	res = malloc(sizeof(char) * n + 1);
	if (!res)
		return (NULL);
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_get_val(char *var, t_env *env)
{
	t_list_env *tmp;

	tmp = env->env;
	while (tmp && strcmp(tmp->var, var) != 0)
		tmp = tmp->next;
	free(var);
	if (tmp && tmp->val)
		return (tmp->val);
	return (NULL);
}

int	ft_count_char(char *line, t_env *env)
{
	int i;
	int j;
	int count;
	char *res;
	t_list_env *tmp;

	i  = 0;
	j = 0;
	count = 0;
	res = NULL;
	while (line[i])
	{
		tmp = env->env;
		if (line[i] == '$')
		{
			j = i + 1;
			while (is_alphanum(line[j]) > 0)
				j++;
			res = ft_strndup(&line[i + 1], j - i - 1);
			while (tmp && strcmp(tmp->var, res) != 0)
			{
				tmp = tmp->next;
			}
			if (tmp && tmp->val)
				count = count + ft_strlen(tmp->val);
			i = j;
				
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	*ft_expansion(char *line, t_env *env)
{
	int	i;
	int	j;
	int 	k;
	char *res;
	char *tmp;

	i = 0;
	j = 0;
	k = 0;
	res = malloc(sizeof(char) * (ft_count_char(line, env) + 1));
	while (line[i])
	{
		if (line[i] == '$')
		{
			j = i + 1;
			while (is_alphanum(line[j]) > 0)
				j++;
			tmp = ft_strndup(&line[i + 1], j - i - 1);
			i = j;
			j = 0;
			tmp = ft_get_val(tmp, env);
			if (tmp)
				while (tmp[j])
				{
					res[k] = tmp[j];
					j++;
					k++;
				}

		}
		else
		{
			res[k] = line[i];
			k++;
			i++;
		}
	}
	res[k] = '\0';
	return (res);
}
