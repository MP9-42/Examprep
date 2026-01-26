/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:15:45 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 22:49:21 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_bits(unsigned char octet)
{
    char c = '\0';
    int bit = 8;
    while (bit != 0)
    {
        c = (octet >> bit & 1) + '0';
        write(1, &c, 1);
        bit--;
    }
}

/* if you want to test your code : */
int main()
{
	unsigned char octet = 32;
	print_bits(octet);
    return(0);
}
