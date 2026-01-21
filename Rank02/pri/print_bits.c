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

// void print_bits(unsigned char octet)
// {
//     int i = 8; // Initialize a counter variable i to 8
//     unsigned char bit = 0; // Initialize a variable bit to 0

//     while (i--) // Loop through each bit of octet
//     {
//         bit = (octet >> i & 1) + 48; // Shift the bit of octet to the right i times and use the bitwise AND operator with 1 to get the bit value. Then add 48 to convert the bit value to its ASCII representation ('0' or '1')
//         write (1, &bit, 1); // Write the ASCII representation of the bit to the standard output (stdout)
//     }
// }








void    print_bits(unsigned char octet)
{
    int i;
    int bit;

    i = 8;
    bit = 0;
    while (i--)
    {
        bit = (octet >> i & 1);
        write(1, &bit, 4);
    }
}






/* if you want to test your code : */
int main()
{
	unsigned char octet = 8;
	print_bits(octet);
}
