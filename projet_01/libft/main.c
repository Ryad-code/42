/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:40:59 by ryad              #+#    #+#             */
/*   Updated: 2020/05/15 21:01:10 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int main()
{
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 30));
//	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "", 10));
}
