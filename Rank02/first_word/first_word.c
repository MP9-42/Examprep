/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:46:37 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 17:29:01 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>\

int	main(int argc, char **argv)
{
	int i = 1;
	int i2 = 0;
	char *first_word;

	if (argc != 2)
		return (0);
	while (argv[i][i2] == ' ')
		i2++;
	while (argv[i][i2] != '\0' && argv[i][i2] != ' ')
	{
		write(1, (&argv[i][i2]), 1);
		if (argv[i][i2 + 1] == '\0')
			write(1, "\n", 1);
		i2++;
	}
	return (0);
}
