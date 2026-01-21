/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:04:27 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 16:55:30 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
int main(int argc, char **argv)
{
	int counter = ft_strlen(argv[1]);
	int	i;
	char *str;
	
	if (argc != 2)
		write(1, "\n", 1);
	while(counter != -1)
	{
		write(1, &argv[1][counter], 1);
		counter--;
	}
	return(0);
}