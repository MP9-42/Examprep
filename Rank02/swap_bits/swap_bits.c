/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:29:32 by MP9               #+#    #+#             */
/*   Updated: 2025/09/03 18:06:05 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

int main()
{
	unsigned char octet;
	int i = 8;
	int bit = 0;

	octet = 'Z';
	while(i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
	write(1, "\n", 1);
	printf("%c\n", octet);
	i = 8;
	octet = swap_bits(octet);
	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
	write(1, "\n", 1);
	printf("%c\n", octet);
	return(0);
}