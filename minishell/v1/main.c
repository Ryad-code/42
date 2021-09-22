/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 19:51:41 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_data data;

	data.buffer = malloc(sizeof(char) * 2048);
	data.len_env = ft_init_env(&data, env);
	data.len_exp = ft_init_exp(&data, env);
	write(1, "$> ",3);
	while (get_next_line(STDIN_FILENO, &data.buffer) > 0 && ft_strcmp(data.buffer, EXIT) < 0)	
	{
		ft_init_words(&data);
		ft_router(&data);
		write(1, "$> ",3);
		free(data.buffer);
	}
	printf("Bye\n");
//	free(data.buffer);
//..................................................................	
//	printf("%p\n", opendir("rrr"));
	return (0);
}
