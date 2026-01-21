/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:08:02 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 22:42:00 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	temp = 0;
	while (i--)
	{
		temp = (temp << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return(temp);
}
int	main()
{
	unsigned char	octet;
	int				i = 8;
	unsigned char	bit = 0;

	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, "%c", bit);
	}
	octet = reverse_bits('a');
	printf("\n");
	bit = 0;
	i = 8;
	while(i--)
	{
		bit = (octet >> i & 1) + 48;
		printf("%c", bit);
	}
	return (0);
}
