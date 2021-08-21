/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/21 21:07:12 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **ag, char **env)
{
	t_data data;

	data.buffer = malloc(sizeof(char) * 2048);
	data.buffer = "bonjour je mappelle ryad";
	data.words = ft_split(data.buffer, ' ');
	data.nb_words = ft_count(data.buffer, ' ');
	ft_display_words(data.words, data.nb_words);
//.................................................................TEST
	
//.................................................................BOUCLE
/*	write(1, "$> ",3);
	while (get_next_line(STDIN_FILENO, &data.buffer) > 0 && ft_strcmp(data.buffer, EXIT) < 0)	
	{
		printf("cmd = %s\n", data.buffer);
		write(1, "$> ",3);
	}
	printf("Bye\n");
	ft_display_words(data.words, data.nb_words);
	free(data.buffer);*/
//..................................................................	
//	printf("%p\n", opendir("rrr"));
	return (0);
}
