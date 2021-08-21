/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/22 01:13:17 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **ag, char **env)
{
	t_data data;

	data.buffer = malloc(sizeof(char) * 2048);
	data.nb_words = ft_count(data.buffer, ' ');
	write(1, "$> ",3);
	while (get_next_line(STDIN_FILENO, &data.buffer) > 0 && ft_strcmp(data.buffer, EXIT) < 0)	
	{
		ft_init_data(&data);
		ft_router(data);
//		ft_display_words(data.words, data.nb_words);
//		printf("nb_words = %d\n", data.nb_words);
//		printf("nb_cmd = %d\n", data.nb_cmd);
		write(1, "$> ",3);
	}
	printf("Bye\n");
	ft_display_words(data.words, data.nb_words);
	free(data.buffer);
//..................................................................	
//	printf("%p\n", opendir("rrr"));
	return (0);
}
