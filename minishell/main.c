/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/24 04:10:43 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **ag, char **env)
{
	t_data data;

	data.buffer = malloc(sizeof(char) * 2048);
	data.len_env = ft_init_env(&data, env);
	data.len_exp = ft_init_exp(&data, env);
	ft_display_list(data.env);
	printf("\n\n");
	ft_display_list(data.exp);
	write(1, "$> ",3);
	while (get_next_line(STDIN_FILENO, &data.buffer) > 0 && ft_strcmp(data.buffer, EXIT) < 0)	
	{
		ft_init_words(&data);
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
