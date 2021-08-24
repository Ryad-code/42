/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 02:46:08 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 19:44:39 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_create_first(char *str)
{
	t_list	*obj;

	obj = malloc(sizeof(t_list));
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->next = NULL;
	obj->prev = NULL;
	return (obj);
}

int ft_create_top(t_list **list, char *str)
{
	t_list  *obj;

	obj = malloc(sizeof(t_list));
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->next = *list;
	obj->prev = NULL;
	(*list)->prev = obj;
	*list = obj;
	return (0);
}

int ft_create_bot(t_list **list, char *str)
{
	t_list  *obj;
	void	*tmp;

	obj = malloc(sizeof(t_list));
	tmp = *list;
	while ((*list)->next)
		*list = (*list)->next;
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->next = NULL;
	obj->prev = *list;
	(*list)->next = obj;
	*list = tmp;
	return (0);
}

int	ft_create_in(t_list **list, char *str, int curs)
{
	int 	i;
	t_list	*obj;
	void	*tmp;

	i = 0;
	obj = malloc(sizeof(t_list));
	tmp = *list;
	while ((*list)->next && i < curs)
	{
		*list = (*list)->next;
		i++;
	}
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->next = *list;
	obj->prev = (*list)->prev;
	(*list)->prev->next = obj;
	(*list)->prev = obj;
	*list = tmp;
	return (0);
}

int	ft_delete_in(t_data *data, t_list **list, int curs)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	if (curs == 0)
		ft_delete_top(list);
	else if (curs == data->len_env)
		ft_delete_bot(list);
	while ((*list)->next && i < curs)
	{
		*list = (*list)->next;
		i++;
	}
	(*list)->next->prev = (*list)->prev;
	(*list)->prev->next = (*list)->next;
	free(*list);
	*list = tmp;
	return (0);
}

int	ft_delete_top(t_list **list)
{
	t_list *tmp;

	tmp = (*list)->next;
	(*list)->next->prev = NULL;
	free(*list);
	*list = tmp;
	return (0);
}

int	ft_delete_bot(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->prev->next = NULL;
	free(*list);
	*list = tmp;
	return (0);
}
