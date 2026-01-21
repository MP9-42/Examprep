#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen (char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	num;
	int	prepoc;

	prepoc = 1;
	num = 0;
	if (!str || ft_strlen(str) >= 11)
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			prepoc = prepoc * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (prepoc * num);
}

char *ft_itoa(int nbr)
{
	char	*number;
	int		counter;
	int 	why;

	counter = 0;
	why = nbr;
	while (why > 9)
	{
		why = nbr / 10;
		counter++;
	}
	while (counter < -1)
	{
		number[counter] = '0' + (nbr % 10);
		counter--;
	}
	return (number);
}

int	main(int argc, char **argv)
{
	int number;
	int	add;
	int	i;
	char *hello;

	i = 2;
	add = 0;
	number = ft_atoi(argv[1]);
	printf("%d\n", number);
	if (argc <= 1 || number <= 1)
	{
		write(1, "0\n", 3);
		return (0);
	}
	while (i < number / 2)
	{
		if (i % i == 0 && i % 1 == 0)
		{
			add = add + i;
			printf("%d\n", i);
			i++;
		}
		else
			printf("%d\n", i);
			printf("%d\n", add);
			i++;
	}
	i = 0;
	hello = ft_itoa(add);
	// while (hello[i] != '\0')
	// {
	// 	write(1, &hello[i], 1);
	// 	i++;
	// }
	// write(1, "\n", 1);
	return (0);
}
