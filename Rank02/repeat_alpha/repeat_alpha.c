/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:01:41 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 21:35:01 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_alphaindex(char letter)
{
	char 	*lalphabet;
	char	*salphabet;
	int		i;
	int		counter;

	i = 0;
	lalphabet = "\nabcdefghijklmnopqrstuvwxyz";
	salphabet = "\nABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (letter >= 65 && letter <= 90 || letter >= 97 && letter <= 122)
	{
		while(letter != lalphabet[i] && lalphabet[i] != '\0')
		{
			i++;
			if (letter == lalphabet[i])
			{
				counter = i;
				while(counter != 0)
				{
					write(1, &lalphabet[i], 1);
					counter--;
				}
			}
		}
		i = 0;
		while(letter != salphabet[i] && salphabet[i] != '\0')
		{
			i++;
			if (letter == salphabet[i])
			{
				counter = i;
				while(counter != 0)
				{
					write(1, &salphabet[i], 1);
					counter--;
				}
			}
		}
	}
	else
		write(1, &letter, 1);
}
int main(int argc, char **argv)
{
	char 	*str;
	int		i;

	str = argv[1];
	if (argc != 2)
		return(write(1, "\n", 1), 0);
	while(argv[1][i] != '\0')
	{
		ft_alphaindex(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return(0);
}