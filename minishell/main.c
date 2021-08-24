/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 02:04:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **ag, char **env)
{
/*	char *s;
	s = malloc(sizeof(char) * 50);
	s = getenv("HOME");
	printf("s = %s\n", s);*/
	t_data data;

	data.buffer = malloc(sizeof(char) * 2048);
	write(1, "$> ",3);
	while (get_next_line(STDIN_FILENO, &data.buffer) > 0 && ft_strcmp(data.buffer, EXIT) < 0)	
	{
		ft_init_data(&data);
		ft_router(data, env);
		write(1, "$> ",3);
		free(data.buffer);
	}
	printf("Bye\n");
//	free(data.buffer);
//..................................................................	
//	printf("%p\n", opendir("rrr"));
	return (0);
}
