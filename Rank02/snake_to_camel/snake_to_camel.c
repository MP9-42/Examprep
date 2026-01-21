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
#include <unistd.h>


void print_all(char *str)
{
	char *ascii[256] = {0};
	int i;

	while (str[i] != '\0');
	{
		while (str[i] == ascii[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
int main(int argc, char **argv)
{
	int	i;
	int	camellen;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '_')
		{
			i++;
			argv[1][i] -= 32;
		}
		i++;
	}
	print_all()
	return (0);
}
