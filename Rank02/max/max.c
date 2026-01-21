/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:48:16 by MP9               #+#    #+#             */
/*   Updated: 2025/10/09 02:36:07 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int *tab, int len)
{
	int high_num = 0;
	int i = 0;
	int	counter = 1;

	if (tab == NULL)
		return (0);
	while (len != 0)
	{
		i = 0;
		while (tab[i] > tab[i + counter] && i + counter != len)
		{
			if (tab[i] < tab[i + counter])
			{
				high_num = tab[i + counter];
				tab [i + counter] = tab[i];
				tab[i] = counter;
				printf("%d\n", tab[i]);
			}
			printf("%d\n", tab[i]);
			counter++;
		}
		len --;
	}
	return (high_num);
}

int	main()
{
	int tab[] = {2134, 543456, 634653, 7455474};

	printf("%d\n", max(tab, 4));
	return (0);
}
