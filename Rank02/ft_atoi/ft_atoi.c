/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:55:29 by MP9               #+#    #+#             */
/*   Updated: 2025/10/08 22:53:35 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int		ft_atoi(char *str)
{
	int	prepocessor;
	int	number;
	int	i;

	prepocessor = 1;
	number = 0;
	if (ft_strlen(str) < 11)
		return (0);
	while (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] <= 13 || str[i] >= 9)
	{
		if (str[i] == '-')
			prepocessor = prepocessor * (-1);
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (prepocessor * number < INT_MIN || prepocessor * number > INT_MAX)
		return (0);
	return (prepocessor * number);
}

int main()
{
	printf("%i", ft_atoi("-24325"));
	return(0);
}
