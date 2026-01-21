/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:29:26 by MP9               #+#    #+#             */
/*   Updated: 2025/09/04 00:09:38 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
	int lookup[256] = {0};
    
    if (argc == 3)
    {
        while(argv[1][i])
        	lookup[(int)argv[1][i++]] = 1;
        i = 0;
        while(argv[2][i])
        	lookup[(int)argv[2][i++]] = 1;
        i = 0;
        while (argv[1][i])
        {
            if (lookup[(int)argv[1][i]])
            {
                write(1, &argv[1][i], 1);
                lookup[(int)argv[1][i]] = 0;
            }
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            if (lookup[(int)argv[2][i]])
            {
                write(1, &argv[2][i], 1);
                lookup[(int)argv[2][i]] = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
