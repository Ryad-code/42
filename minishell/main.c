/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/08/21 19:48:26 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **ag, char **env)
{
	char *buffer;
	char *exit = "exit";
	char *ex = "bonjour je suis Ryad\0";
	char **tmp;

//	tmp = NULL;
//	buffer = malloc(sizeof(char) * 2048);
/*	if (buffer == NULL)
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	write(1, "$> ",3);
	while (get_next_line(STDIN_FILENO, &buffer) > 0 && ft_strcmp(buffer, exit) < 0)	
	{
		printf("cmd = %s\n", buffer);
		write(1, "$> ",3);
	}
	printf("Bye\n");
	free(buffer);*/
	tmp = ft_split(ex, ' ');
	printf("tmp = %s\n", tmp[0]);
	printf("tmp = %s\n", tmp[1]);
	printf("tmp = %s\n", tmp[2]);
	printf("tmp = %s\n", tmp[3]);

//..................................................................	
/*	pid_t pid;
	pid = fork();
	if (!pid)
	{
		printf("child1\n");
		pid2 = fork();
	}
	if(pid)
	{
		printf("parent1\n");
	}*/
//.....................................................................
	return (0);
}
