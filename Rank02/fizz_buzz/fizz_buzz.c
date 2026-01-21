/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:23:24 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 17:03:21 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	main()
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			write(1, "fizzbuzz\n", 10);
			i++;
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz\n", 6);
			i++;
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz\n", 6);
			i++;
		}
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}