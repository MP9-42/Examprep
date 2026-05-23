/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:47:03 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 23:13:38 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return(1);
	}
	int i = 0;
	while(argv[1][i] != '\0')
	{
		if(argv[1][i] == '_')
		{
			argv[1][i + 1] -= 32;
			i++;
			write(1, &argv[1][i], 1);
			i++;
		}
		else
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}